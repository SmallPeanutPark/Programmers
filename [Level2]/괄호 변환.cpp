#include <string>
#include <vector>
#include <stack>

using namespace std;

// 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
pair<string, string> separateStr(string str) {
    int leftstr = 0; // '(' 의미
    int rightstr = 0; // ')' 의미
    string tempstr = ""; // 임시 str
    pair<string, string> pairstr; // 반환하기 위한 pair
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            leftstr += 1;
            tempstr += str[i];
        }
        else {
            // ')'
            rightstr += 1;
            tempstr += str[i];
        }

        if (leftstr == rightstr) {
            // '('와 ')' 갯수가 처음으로 같아질 때(최소) first에 u값 저장
            pairstr.first += tempstr;
            break;
        }
    }

    // 전체 문자열에서 u의 값을 제외한 나머지를 second에 v값 저장
    pairstr.second = str.substr(leftstr + rightstr);
    return pairstr;
}

// 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
bool correctStr(string str) {
    stack<char> st; // stack 사용
    for (int i = 0; i < str.length(); ++i) {
        if (st.empty()) {
            if (str[i] == '(') {
                st.push(str[i]);
            }
        }
        else {
            if (st.top() == '(') {
                if (str[i] == ')') {
                    st.pop();
                }
                else {
                    st.push(str[i]);
                }
            }
        }
    }
    if (st.empty()) {
       // 올바른 괄호 문자열
        return true;
    }
    return false;
}



string solution(string p) {
    string answer = "";
    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
    if (p.compare("") == 0) { 
        return "";
    }
    else {
        // 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
        pair<string, string> pairvalue = separateStr(p);
        if (correctStr(pairvalue.first)) {
            // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
            // 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
            pairvalue.first += solution(pairvalue.second);
            answer = pairvalue.first;
            return answer;
        }
        else {
            // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
            string str = "";
            
            // 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
            str += '(';
            
            // 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
            str += solution(pairvalue.second);
            
            // 4-3. ')'를 다시 붙입니다.
            str += ')';

            for (int i = 0; i < pairvalue.first.length(); ++i) {
                if ((i == 0) || (i == pairvalue.first.length() - 1)) {
                    // 4-4. u의 첫 번째와 마지막 문자를 제거하고,
                }
                else {
                    // 4-4. 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
                    if (pairvalue.first[i] == '(') {
                        str += ')';
                    }
                    else {
                        str += '(';
                    }
                }
            }
            // 4-5. 생성된 문자열을 반환합니다.
            answer = str;
            return answer;
        }
    }
}

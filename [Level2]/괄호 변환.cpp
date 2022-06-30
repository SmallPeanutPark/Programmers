#include <string>
#include <vector>
#include <stack>

using namespace std;


pair<string, string> separateStr(string str) {
    int leftstr = 0;
    int rightstr = 0;
    string tempstr = "";
    pair<string, string> pairstr;
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
            pairstr.first += tempstr;
            break;
        }
    }

    pairstr.second = str.substr(leftstr + rightstr);
    return pairstr;
}

bool correctStr(string str) {
    stack<char> st;
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
       // 올바른 문자열
        return true;
    }
    return false;
}



string solution(string p) {
    string answer = "";
    if (p.compare("") == 0) {
        return "";
    }
    else {
        pair<string, string> pairvalue = separateStr(p);
        if (correctStr(pairvalue.first)) {
            pairvalue.first += solution(pairvalue.second);
            answer = pairvalue.first;
            return answer;
        }
        else {
            string str = "";
            str += '(';
            str += solution(pairvalue.second);
            str += ')';

            for (int i = 0; i < pairvalue.first.length(); ++i) {
                if ((i == 0) || (i == pairvalue.first.length() - 1)) {
                    // pass
                }
                else {
                    if (pairvalue.first[i] == '(') {
                        str += ')';
                    }
                    else {
                        str += '(';
                    }
                }
            }
            answer = str;
            return answer;
        }
    }
}

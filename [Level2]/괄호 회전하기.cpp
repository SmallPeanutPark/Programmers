#include <string>
#include <vector>
#include <stack>
#include <deque>


using namespace std;

bool isCorrect(deque<char> d) {
    stack<char> fullstack; // 소,중,대 괄호 모두 포함

    int len = d.size();

    for(int i = 0; i < len; ++i) {
        if(d[i] == '{') {
            fullstack.push(d[i]);
        } else if(d[i] == '}') {
            if(!fullstack.empty()) {
                if(fullstack.top() == '{') {
                    fullstack.pop();
                }
            } else {
                fullstack.push(d[i]);
            }
        } else if(d[i] == '[') {
            fullstack.push(d[i]);
        } else if(d[i] == ']') {
            if(!fullstack.empty()) {
                if(fullstack.top() == '[') {
                    fullstack.pop();
                }
            } else {
                fullstack.push(d[i]);
            }
        }
        else if(d[i] == '(') {
            fullstack.push(d[i]);
        } else if(d[i] == ')') {
            if(!fullstack.empty()) {
                if(fullstack.top() == '(') {
                    fullstack.pop();
                }
            } else {
                fullstack.push(d[i]);
            }
        } else {
            // nothing
        }
    }

    if(!fullstack.empty()) {
        return false;
    } else {
        return true;
    }

}

void rotationDeque(deque<char>& d) {
    d.push_back(d.front());
    d.pop_front();
}

int solution(string s) {
    int answer = 0;
    int len = s.length();
    deque<char> dq;
    for(int i = 0; i < len; ++i) {
        dq.push_back(s[i]);
    }

    while(len != 0) {
        if(isCorrect(dq)) {
            ++answer;
        }
        rotationDeque(dq);
        --len;
    }

    
    return answer;
}

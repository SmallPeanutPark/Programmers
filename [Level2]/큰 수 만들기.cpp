#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    stack<int> st;
    int len = number.length();
    for (int i = 0; i < len; ++i) {
        if (st.empty()) {
            st.push(number[i] - '0');
        }
        else {
            while (!st.empty() && (st.top() < number[i] - '0') && k != 0) {
                st.pop();
                k -= 1;
            }
            st.push(number[i] - '0');
        }
    }

    while (k != 0) {
        st.pop();
        k -= 1;
    }

    string answer;
    while (!st.empty()) {
        answer += to_string(st.top());
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

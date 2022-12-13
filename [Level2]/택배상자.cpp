#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

queue<int> q; // 기존 컨테이너
stack<int> st; // 보조 컨테이너

void setInitBox(int len) {
    // 초기 택배 상자를 기존 컨테이너에 셋팅
    for(int i = 0; i < len; ++i) {
        q.push(i+1); 
    }
}

int setWantBoxOrder(vector<int> order, int len) {
    int count = 0;
    bool ispass = false;
    for(int i = 0; i < len; ++i) {
        if(!st.empty()) {
            if(st.top() == order[i]) {
                st.pop();
                count += 1;
                ispass = false;
                continue;
            }
        }

        if(q.front() != order[i]) {
            // 택배 상자를 실어야할 순서가 아니라면 택배를 다른 곳으로 보관해야한다.
            while((!q.empty()) && (q.front() != order[i])) {
                st.push(q.front());
                q.pop();
            }
            if(q.front() == order[i]) {
                q.pop();
                count += 1;
                ispass = false;
            } else {
                // 기존 컨테이너에서 찾지못했을 때
                ispass = true;
            }
        } else {
            // 택배 상자를 실어야할 박스가 기존 컨테이너에 있을 때
            ispass = false;
            q.pop();
            count += 1;
        }

        if(ispass) break;
    }
    return count;
}

int solution(vector<int> order) {
    int gSize = order.size();
    setInitBox(gSize);
    int answer = setWantBoxOrder(order, gSize);
    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> max_pq; // 최대힙
priority_queue<int, vector<int>, greater<int>> min_pq; // 최소 힙

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int gSize = operations.size();
    int minCnt = 0;
    int maxCnt = 0;
    for(int i = 0; i < gSize; ++i) {
        string s = operations[i];
        if(s[0] == 'I') {
            // 삽입
            string temp = "";
            if(s[2] == '-') {
                // 음수
                temp += s.substr(2, s.length());
            } else {
                // 양수
                temp += s.substr(2, s.length());
            }
            max_pq.push(stoi(temp));
            min_pq.push(stoi(temp));
        } else {
            // s[0] == 'D' 삭제
            if(s[2] == '-') {
                // 최소 힙 삭제
                if(!min_pq.empty()) {
                    min_pq.pop();

                }
                minCnt += 1;

                if(!max_pq.empty()) {
                    vector<int> v;
                    int maxpqSize = max_pq.size();
                    for(int i = 0; i < maxpqSize - minCnt; ++i) {
                        int num = max_pq.top();
                        max_pq.pop();
                        v.emplace_back(num);
                    }
                    priority_queue<int> temppq;
                    max_pq.swap(temppq);
                    for(int i = 0; i < maxpqSize - minCnt; ++i) {
                        max_pq.push(v[i]);
                    }
                    minCnt = 0;
                }
            } else {
                if(!max_pq.empty()) {
                    // 최대 힙 삭제
                   max_pq.pop();
                }
                maxCnt += 1;

                if(!min_pq.empty()) {
                    vector<int> v;
                    int minpqSize = min_pq.size();
                    for(int i = 0; i < minpqSize - maxCnt; ++i) {
                        int num = min_pq.top();
                        min_pq.pop();
                        v.emplace_back(num);
                    }
                    priority_queue<int, vector<int>, greater<int>> temppq;
                    min_pq.swap(temppq);
                    for(int i = 0; i < minpqSize - maxCnt; ++i) {
                        min_pq.push(v[i]);
                    }
                    maxCnt = 0;
                }
            }
        }
    }

    if(max_pq.empty()) {
        answer.emplace_back(0);
    } else {
        answer.emplace_back(max_pq.top());
    }

    if(min_pq.empty()) {
        answer.emplace_back(0);
    } else {
        answer.emplace_back(min_pq.top());
    }
    
    return answer;
}

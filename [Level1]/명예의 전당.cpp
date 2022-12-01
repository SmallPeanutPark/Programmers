#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    int gSize = score.size();
    int day = 0;
    for(int i = 0; i < gSize; ++i) {
        if(pq.size() < k) {
            day += 1;
            pq.push(score[i]);
            if(!pq.empty()) answer.emplace_back(pq.top());
        } else {
            if(pq.top() < score[i]) {
                pq.pop();
                pq.push(score[i]);
                answer.emplace_back(pq.top());
            } else {
                answer.emplace_back(pq.top());
            }
        }
    }
    return answer;
}

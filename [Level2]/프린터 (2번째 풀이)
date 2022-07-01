#include <vector>
#include <string>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, string>> q;
    priority_queue<int> pq;

    for (int k = 0; k < priorities.size(); ++k) {
        if (location == k) {
            q.push(make_pair(priorities[k], "Yes"));
        }
        else {
            q.push(make_pair(priorities[k], "No"));
        }
        pq.push(priorities[k]);
    }

    while (!q.empty()) {
        if (pq.top() == q.front().first) {
            if (q.front().second.compare("Yes") == 0) {
                // location 인지 확인
                answer += 1;
                break;
            }

            pq.pop();
            q.pop();
            answer += 1;
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }

    return answer;
}

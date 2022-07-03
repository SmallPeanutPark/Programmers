#include <vector>
#include <string>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, string>> q; // 인쇄 대기 목록
    priority_queue<int> pq;

    for (int k = 0; k < priorities.size(); ++k) {
        if (location == k) {
            // 인쇄 요청한 문서인 경우 "Yes"로 기록
            q.push(make_pair(priorities[k], "Yes"));
        }
        else {
            q.push(make_pair(priorities[k], "No"));
        }
        pq.push(priorities[k]); // 인쇄 대기 목록에서 값(인쇄 우선 순위)이 큰 순서대로 데이터가 저장됨
    }

    while (!q.empty()) {
        // 우선 순위 큐 top과 큐의 front.first 같은지 확인
        if (pq.top() == q.front().first) {
            if (q.front().second.compare("Yes") == 0) {
                // 내가 찾고자하는 인쇄 문서인지 확인
                answer += 1;
                break;
            }
            
            // 같다면 우선 순위 큐와 큐에서 pop
            pq.pop();
            q.pop();
            answer += 1;
        }
        else {
            // 우선 순위 큐 top과 큐의 front.first 같지 않다면, 우선 순위가 뒤에 있음으로 큐의 뒤로 보냄
            q.push(q.front());
            q.pop();
        }
    }

    return answer;
}

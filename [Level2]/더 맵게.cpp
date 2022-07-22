#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int element : scoville) {
        pq.emplace(element);
    }
    
    int num = pq.top();
    while (true) {
        if (!pq.empty()) {
            if (num < K) {
                pq.pop();
                if (!pq.empty()) {
                    ++answer;
                    int result = num + (pq.top() * 2);
                    pq.pop();
                    pq.emplace(result);
                    num = pq.top();
                }
            }
            else {
                break;
            }
        }
        else {
            break;
        }
    }

    if (pq.top() < K) {
        answer = -1;
    }

    return answer;
}

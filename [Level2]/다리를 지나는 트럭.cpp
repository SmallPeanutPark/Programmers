#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    int truckcnt = 0;
    int total_weight = 0;

    for (const auto& element : truck_weights) {
        while (true) {
            if (bridge.empty()) {
                // 다리에 트럭 없을 때
                if (element <= weight) {
                    // 조건 만족 시 다리위에 올린다
                    bridge.push(element);
                    answer += 1;
                    total_weight += element;
                    truckcnt++;
                    break;
                }
            }
            else if (bridge.size() == bridge_length) { // 다리 길이 만큼 다 찬경우
                if (bridge.front() != 0) {
                    truckcnt -= 1;
                }
                total_weight -= bridge.front();
                bridge.pop();
            }
            else {
                // 다리에 트럭 있을 때 올릴 수 있는지 확인
                if ((total_weight + element <= weight)
                && (element <= weight)
                && (truckcnt <= bridge_length)) {
                    // 올릴 수 있음
                    bridge.push(element);
                    answer += 1;
                    total_weight += element;
                    truckcnt++;
                    break;
                }
                else {
                    // 올릴 수 없음
                    // 트럭들은 움직인다.
                    answer++;
                    bridge.push(0);
                    // 트럭 이동
                }
            }
        }
    }
    
    answer += bridge_length;


    return answer;
}

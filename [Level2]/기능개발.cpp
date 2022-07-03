#include <string>
#include <vector>
#include <queue>

using namespace std;

int calculateday(int working, int speed) {
    int extrawork = 100 - working;
    int day = 0;
    while (extrawork > 0) {
        extrawork -= speed;
        day += 1;
    }

    return day;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> workingday; // 작업 일 수 저장하기 위한 queue

    int len = progresses.size();
    for (int k = 0; k < len; ++k) {
        workingday.push(calculateday(progresses[k], speeds[k])); // 작업 일수 계산
    }

    int day = workingday.front(); // 처음 작업 일수를 기준 값으로 설정 
    int popcnt = 0;
    while (!workingday.empty()) {
        workingday.pop();
        if (!workingday.empty()) {
            if (day < workingday.front()) {
                // 같이 배포 불가능
                popcnt++;
                answer.push_back(popcnt);
                day = workingday.front();
                popcnt = 0;
            }
            else {
                // 같이 배포 가능
                // day 값을 유지 해야함
                popcnt++;
                continue;
            }
        }
        else {
            popcnt++;
            answer.push_back(popcnt);
            popcnt = 0;
        }
    }

    return answer;
}

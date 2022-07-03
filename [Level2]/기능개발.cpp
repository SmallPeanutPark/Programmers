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
    vector<int> workingday; // 작업 일 수 저장하기 위한 vector
    queue<int> success_work;

    int len = progresses.size();
    for (int k = 0; k < len; ++k) {
        workingday.push_back(calculateday(progresses[k], speeds[k])); // 작업 일수 계산
    }

    int day = workingday.front(); // 처음 작업 일수를 기준 값으로 설정 
    int popcnt = 0;
    for (int k = 0; k < len; ++k) {
        if (day >= workingday[k]) {
            // 배포 가능
            success_work.push(workingday[k]);
        }
        else {
            // 배포 불가능
            answer.push_back(success_work.size());

            while (!success_work.empty()) {
                success_work.pop();
            }

            day = workingday[k]; // 기준 값 변경
            success_work.push(workingday[k]);
        }
    }

    answer.push_back(success_work.size());
   

    return answer;
}

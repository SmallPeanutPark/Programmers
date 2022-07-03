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
    
    for (int k = 0; k < len; ++k) {
        if (day >= workingday[k]) {
            // 배포 가능하여 큐에 넣는다.
            success_work.push(workingday[k]);
        }
        else {
            // 배포 불가능, 이전 작업을 완료해야함
            answer.push_back(success_work.size());

            // 이전 작업 목록 초기화
            while (!success_work.empty()) {
                success_work.pop();
            }

            day = workingday[k]; // 기준 값 변경
            success_work.push(workingday[k]); // 배포 가능하여 큐에 넣는다.
        }
    }

    // 마지막 반복문의 경우 이전 작업을 완료하는 부분을 하지 못함으로 answer에 큐 사이즈만큼 push_back 해준다.
    answer.push_back(success_work.size());
   

    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    // 내림 차순 정렬
    sort(lottos.begin(), lottos.end(), greater<int>());
    sort(win_nums.begin(), win_nums.end(), greater<int>());

    int lottos_len = lottos.size();
    int zero_cnt = 0;

    for (int element : lottos) {
        if (element == 0) {
            ++zero_cnt; // 지워진 번호 개수 구하기
        }
    }

    vector<int> different_number;
    int correct_number = 0;
    for (int element : win_nums) {
        for (int n : lottos) {
            if (element != n) {
                // nothing
            }
            else {
                ++correct_number; // 맞힌 개수
            }
        }
    }
    
    // 최저 순위는 지워진 번호 개수만큼 다 틀리기 (nothing)
    // 현재 맞힌 개수만 맞으면 됨
    int check_correct_number = correct_number;

    // 최고 순위는 지워진 번호 개수만큼 다 맞기
    for (int i = 0; i < zero_cnt; ++i) {
        ++correct_number;
    }

    // 최고 순위 체크
    switch (correct_number)
    {
        case 6: {
            // 1등
            answer.push_back(1);
        }
        break;
        case 5: {
            // 2등
            answer.push_back(2);
        }
        break;
        case 4: {
            // 3등
            answer.push_back(3);
        }
        break;
        case 3: {
            // 4등
            answer.push_back(4);
        }
        break;
        case 2: {
            // 5등
            answer.push_back(5);
        }
        break;
        default:
            // 6등
            answer.push_back(6);
        break;
    }


    switch (check_correct_number)
    {
    case 6: {
        // 1등
        answer.push_back(1);
    }
          break;
    case 5: {
        // 2등
        answer.push_back(2);
    }
          break;
    case 4: {
        // 3등
        answer.push_back(3);
    }
          break;
    case 3: {
        // 4등
        answer.push_back(4);
    }
          break;
    case 2: {
        // 5등
        answer.push_back(5);
    }
          break;
    default:
        // 6등
        answer.push_back(6);
        break;
    }

    return answer;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
        int answer = 0;
    vector<int> all_student; // 총 학생
    
    for (int i = 0; i < n; ++i)
    {
        all_student.push_back(1); // 총 학생이 체육복이 있다고 가정
    }

    for (int i = 0; i < lost.size(); ++i) // 총 학생 중에 잃어 버린 학생을 찾아서 -1
    {
        all_student[lost[i] -1] -= 1;
    }

    for (int i = 0; i < reserve.size(); ++i) // 총 학생 중에 여분의 옷 갖고 있는 학생 +1
    {
        all_student[reserve[i] - 1] += 1;
    }

    // 0인 경우 체육복 없음, 1인 경우 체육복 1벌, 2인 경우 여벌 체육복 있음
    for (int i = 0; i < all_student.size(); ++i)
    {
        if ((i != 0) && (all_student[i] > 1) && ( i != all_student.size() -1))
        // 여분의 체육복 있음, 맨 앞, 맨뒤 학생은 제외함
        {
            if(all_student[i-1] == 0) // 왼쪽 학생이 여분의 체육복이 없는 경우
            {
                all_student[i -1] +=1;
                all_student[i] -= 1;
            }
            else if(all_student[i+1] == 0) // 오른쪽 학생이 여분의 체육복이 없는 경우
            {
                all_student[i+1] += 1;
                all_student[i] -= 1;
            }
        }
        else if((i == 0) && (all_student[i] > 1))
        // 맨 앞의 학생이고 여분의 체육복이 있을 때 오른쪽 학생이 없는 경우에만 체육복 줄 수 있음
        {
            if(all_student[i+1] == 0)
            {
                all_student[i+1] += 1;
                all_student[i] -= 1;
            }
        }
        else if((i == all_student.size() -1) && (all_student[i] > 1))
        // 맨 뒤 학생이 여분의 체육복 있음
        {
            // 앞에 있는 학생이 여분 체육복이 없을 때만 줄 수 있음
            if(all_student[i-1] == 0)
            {
                all_student[i-1] += 1;
                all_student[i] -= 1;
            }
        }
    }
    
    
    // 체육수업 들을 수 있는 학생 수 확인
     for(int i = 0; i < all_student.size(); ++i)
     {
          if(all_student[i] > 0) // 0보다 큰 경우는 체육복이 있다는 의미
          {
               ++answer;
          }
     }
    
    return answer;
}

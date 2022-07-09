#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    int count = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        if ((arr[i] % divisor) == 0) // vector 원소 값을 divisor로 나누었을 때 나누어지는 경우
        {
            ++count; // count 값이 0이 아니라면 무조건 나누어 떨어지는 원소 있음
            answer.push_back(arr[i]); //나누어지는 vector 원소 값 push_back
        }
    }

    if (count == 0) //vector 내 나누어떨어지는 원소가 없는 경우
    {
        answer.push_back(-1); // -1 push_back
    }

    sort(answer.begin(), answer.end()); // 오름 차순 정렬

    return answer;
}

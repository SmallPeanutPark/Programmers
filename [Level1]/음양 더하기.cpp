#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int len = absolutes.size();
    
    for (int i = 0; i < len; ++i) {
        if (signs[i]) {
            // 양
            absolutes[i] = abs(absolutes[i]);
        }
        else {
            // 음
            absolutes[i] = abs(absolutes[i]) * -1;
        }
    }


    for (int element : absolutes) {
        answer += element;
    }

    return answer;
}

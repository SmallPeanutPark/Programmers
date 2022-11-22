#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calculateAppleBox(int k, int m, vector<int>& apple) {
    int appleLength = apple.size();
    int appleCnt = 0;
    int totalScore = 0;
    vector<int> gBox;
    for(int i = 0; i < appleLength; ++i) {
        appleCnt += 1;
        if(appleCnt == m) {
            appleCnt = 0;
            gBox.emplace_back(apple[i]);
            totalScore += (gBox[m - 1] * m * 1);
            gBox.clear();
        } else {
            gBox.emplace_back(apple[i]);
        }
    }
    return totalScore;
}

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<int>()); // 내림 차순 정렬
    int answer = calculateAppleBox(k, m, score);
    return answer;
}

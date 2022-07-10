#include <string>
#include <vector>

using namespace std;

int isCheckNumberCnt(int number) {
    // 약수 개수 구하기
    int cnt = 0;
    for (int i = 1; i <= number; ++i) {
        if (number % i == 0) {
            ++cnt;
        }
    }

    return cnt;
}

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; ++i) {
        if (isCheckNumberCnt(i) % 2 == 0) {
            // 약수 갯수 짝수 (더한다)
            answer += i;
        }
        else {
            // 약수 개수 홀수 (뺀다)
            answer -= i;
        }
    }

    return answer;
}

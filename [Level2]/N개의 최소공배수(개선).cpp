#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 최대 공약수 구하기
int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

// 최소 공배수 구하기
int lcd(int a, int b) {
    return a * b / gcd(a, b);
}


int solution(vector<int> arr) {
    int answer = 0;
    // 최대 공약수를 구하고 최소 공배수를 구할 수 있다.
    sort(arr.begin(), arr.end(), greater<int>()); // 내림 차순 정렬

    int len = arr.size();
    answer = arr[0];
    for(int i = 1; i < len; ++i) {
        answer = lcd(answer, arr[i]);
    }

    return answer;
}

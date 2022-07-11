#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int number) {
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false; // 소수 아님
        }
    }
    return true;
}

int solution(vector<int> nums) {
    sort(nums.begin(), nums.end()); // next_permutation을 사용하기 위해선 오름 차순 정렬해야함
    int answer = 0;
    int len = nums.size();
    vector<bool> selected(len);
    fill(selected.end()-3, selected.end(), true);
    do {
        int sum = 0;
        for (int i = 0; i < len; ++i) {            
            if (selected[i]) {
                sum += nums[i];
            }
        }

        if (isPrime(sum)) {
            ++answer;
        }
        // 오름 차순으로 정렬이되면 내림 차순으로 조합이 생성됨
    } while (next_permutation(selected.begin(), selected.end()));

    return answer;
}

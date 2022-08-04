#include <string>
#include <vector>
#include <iostream>

using namespace std;

int copy_target;
vector<int> copy_numbers;
int answer;

void dfs(int num, int sum) {
    if (num == copy_numbers.size()) {
        if (sum == copy_target) answer += 1;
        return;
    }

    dfs(num + 1, sum + copy_numbers[num]);
    dfs(num + 1, sum - copy_numbers[num]);
}

int solution(vector<int> numbers, int target) {
    copy_target = target;
    copy_numbers = numbers;
    answer = 0;
    dfs(0, 0);
    return answer;
}

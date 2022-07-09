#include <string>
#include <vector>

using namespace std;

int arr[10] = { 0, };

int solution(vector<int> numbers) {
    int answer = 0;
    int len = numbers.size();

    for (int i = 0; i < len; ++i) {
        arr[numbers[i] - 0] += 1;
    }

    for (int i = 0; i < 10; ++i) {
        if (arr[i] == 0) {
            answer += i;
        }
    }

    return answer;
}

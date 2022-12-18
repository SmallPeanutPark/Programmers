#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -100000000;
    int len = numbers.size();
    for(int i = 0; i < len; ++i) {
        for(int j = i + 1; j < len; ++j) {
            answer = max(answer, numbers[i] * numbers[j]);
        }
    }
    return answer;
}

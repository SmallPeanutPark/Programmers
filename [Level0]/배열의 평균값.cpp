#include <string>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

double solution(vector<int> numbers) {
    double answer = accumulate(numbers.begin(), numbers.end(), 0);
    double gSize = numbers.size();
    answer /= gSize;
    return answer;
}

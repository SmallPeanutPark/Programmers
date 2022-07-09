#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string str = to_string(n);

    sort(str.begin(), str.end(), greater<int>());

    answer = stoll(str, 0);

    return answer;
}

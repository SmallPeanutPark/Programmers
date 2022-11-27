#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.emplace_back(n);
    for(int i = 1; i <= n / 2; ++i) {
        if(n % i == 0) answer.emplace_back(i);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

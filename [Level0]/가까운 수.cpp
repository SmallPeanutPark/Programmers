#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> pv;

int solution(vector<int> array, int n) {
    int answer = 0;
    for(int element : array) {
        pv.emplace_back(make_pair(abs(n - element), element));
    }
    sort(pv.begin(), pv.end());
    answer = pv[0].second;
    return answer;
}

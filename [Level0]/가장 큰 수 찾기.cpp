#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int maxValue = *max_element(array.begin(), array.end());
    answer.emplace_back(maxValue);
    for(int i = 0; i < array.size(); ++i) {
        if(array[i] == maxValue) answer.emplace_back(i);
    }
    return answer;
}

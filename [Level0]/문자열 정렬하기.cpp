#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for(int i = 0; i < my_string.length(); ++i) {
        if(isdigit(my_string[i])) answer.emplace_back(my_string[i] - '0');
    }
    sort(answer.begin(), answer.end());
    return answer;
}

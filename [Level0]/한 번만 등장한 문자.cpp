#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> m;
    for(int i = 0; i < s.length(); ++i) {
        m[s[i]] += 1;
    }
    for(auto iter = m.begin(); iter != m.end(); ++iter) {
        if(iter->second == 1) answer += iter->first;
    }
    sort(answer.begin(), answer.end());
    return answer;
}

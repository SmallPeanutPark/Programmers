#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int len = clothes.size();
    map<string, int> m;
    for(int i = 0; i < len; ++i) {
         vector<string> temp = clothes[i];
         m[temp[1]] += 1;
    }

    for(auto iter = m.begin(); iter != m.end(); ++iter) {
        answer *= (iter->second + 1);
    }
    answer -= 1;
    return answer;
}

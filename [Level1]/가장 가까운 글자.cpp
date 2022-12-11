#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<char, int> saveidx;

vector<int> solution(string s) {
    string s1 = " ";
    s1 += s;

    int len = s1.length();

    vector<int> answer;
    for(int i = 1; i < len; ++i) {
        if(saveidx.find(s1[i]) == saveidx.end()) {
            // 처음 나온 경우
            saveidx[s1[i]] = i;
            answer.emplace_back(-1);
        } else {
            // 처음 나오지 않은 경우
            answer.emplace_back(i - saveidx[s1[i]]);
            saveidx[s1[i]] = i; // 인덱스 위치 변경 
        }
    }

    return answer;
}

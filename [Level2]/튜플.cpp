#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

// 숫자, 숫자가 나온 횟수 저장
map<string, int> tuple_info;
// 정렬을 위함
vector<pair<string, int>> pv;

void changeMapToVector() {
    for(auto iter = tuple_info.begin(); iter != tuple_info.end(); ++iter) {
        pair<string, int> p(iter->first, iter->second);
        pv.emplace_back(p);
    }
}

bool cmp(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    int gLength = s.length();
    string temp = "";
    // 맨 앞 '{' 와 맨 뒤 '}' 을 제외
    for(int i = 0; i < gLength; ++i) {
        if((s[i] == '{') || (s[i] == '}')) {
            if(!temp.empty()) {
                tuple_info[temp] += 1;
                temp.clear();
            }
            continue;
        } else if(s[i] == ',') {
            if(!temp.empty()) {
                tuple_info[temp] += 1;
                temp.clear();
            }
            continue;
        } else {
            temp += s[i];
        }
    }
    changeMapToVector();
    sort(pv.begin(), pv.end(), cmp); // 갯수가 큰 순서대로 정렬
    int gSize = pv.size();
    for(int i = 0; i < gSize; ++i) {
        answer.emplace_back(stoi(pv[i].first));
    }
    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> answer; // 정답
map<string, int> dictionary; // 사전
vector<string> alpa = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
                      "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

void initialize() {
    int len = alpa.size();
    for(int i = 0; i < len; ++i) {
        dictionary[alpa[i]] = (i + 1);
    }
}

bool isfind(string w) {
    auto result = dictionary.find(w);
    if(result != dictionary.end()) {
        // 찾음
        return true;
    } else {
        return false;
    }
}

vector<int> solution(string msg) {
    initialize(); // 1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    int idx = 26;
    string w = "";
    for(char c : msg) {
        string wc = w + c;
        if(isfind(wc)) {
            w.clear();
            w += wc;
        } else {
            dictionary[wc] = ++idx; // 사전에 등록
            if(isfind(w)) {
                answer.emplace_back(dictionary[w]);
                w.clear();
                w += c;
            }
        }
    }
    if(isfind(w)) {
        answer.emplace_back(dictionary[w]);
    }
    return answer;
}

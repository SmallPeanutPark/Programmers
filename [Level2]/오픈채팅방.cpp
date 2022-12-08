#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

map<string, string> id;
vector<string> info = {"Enter", "Leave", "Change"}; // 들어옴, 떠남, 변경함

void divideStr(vector<string> r, int len) {
    for(int i = 0; i < len; ++i) {
        stringstream ss(r[i]);
        string token = "";
        string s[3];
        int idx = 0;
        while(ss >> token) {
            // 공백을 기준으로 파싱
            s[idx++] = token;
        }

        if(info[0].compare(s[0]) == 0) {
            // Enter
            id[s[1]] = s[2];
        } else if(info[1].compare(s[0]) == 0) {
            // Leave -> nothing
        } else {
            // Change
            id[s[1]] = s[2];
        }
    }
} 


vector<string> solution(vector<string> record) {
    vector<string> answer;
    int len = record.size();
    divideStr(record, len);
    for(int i = 0; i < len; ++i) {
        stringstream ss(record[i]);
        string token = "";
        string s[3];
        int idx = 0;
        while(ss >> token) {
            // 공백을 기준으로 파싱
            s[idx++] = token;
        }
        
        if(info[0].compare(s[0]) == 0) {
            // Enter
           if(id.find(s[1]) != id.end()) {
                string str = id[s[1]];
                str += "님이 들어왔습니다.";
                answer.emplace_back(str);
           }
        } else if(info[1].compare(s[0]) == 0) {
            // Leave
            if(id.find(s[1]) != id.end()) {
                string str = id[s[1]];
                str += "님이 나갔습니다.";
                answer.emplace_back(str);
            }
        } else {
            // do nothing
            continue;
        }
    }
    return answer;
}

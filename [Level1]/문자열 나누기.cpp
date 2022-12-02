#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> d;

void divideStr(string str) {
    string plus = ""; // 읽은 문자열 
    plus += str[0];
    
    char first = str[0]; // 첫글자
    
    int samecnt = 1; // 같은 글자 개수
    int differcnt = 0; // 다른 글자 개수
    
    int len = str.length();
    bool isinit = false;
    for(int i = 1; i <= len; ++i) {
        if(isinit == true) {
            // 초기값 읽을 때
            isinit = false;
            first = str[i];
            plus += str[i];
            samecnt += 1;
        } else {
            // 초기값 이후
            if(first == str[i]) {
                samecnt += 1;
                plus += str[i];
            } else {
                // first != str[i] 서로 다른 글자일 때
                differcnt += 1;
                plus += str[i];
                // 같은 글자의 개수와 다른 글자의 개수가 동일할 때 정지
                if(samecnt == differcnt) {
                    // 초기화
                    samecnt = 0;
                    differcnt = 0;
                    d.emplace_back(plus);
                    plus.clear();
                    isinit = true;
                }
            }
            if(samecnt != differcnt) {
                // 두 횟수가 다른 상태
                
                // 더이상 읽을 글자가 없다 -> 문자열의 끝을 의미하는 것으로 보임
                if(i == len) {
                    d.emplace_back(plus);
                }
            }
        }
    }
}

int solution(string s) {
    divideStr(s);
    int answer = d.size();
    return answer;
}

#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
using namespace std;

vector<tuple<string, string, string>> t; // HEAD, NUMBER, TAIL

void divideStr(string str) {
    string plus[3]; // HEAD, NUMBER, TAIL
    int idx = 0;
    int numbercnt = 5;
    bool isEnd = false; // TAIL 구분
    for(char element : str) {
        if(isalpha(element)) {
            // HEAD: 문자로 이루어짐, 최소한 1글자 이상
            // isalpha 알파벳 문자인경우
            if(isEnd) {
                idx = 2;
            } else {
                idx = 0;
            }
            plus[idx] += element;
        } else {
            if((idx == 2) && (isdigit(element))) {
                idx = 2;
            } 
            else if(isdigit(element)) {
                // NUMBER : 0 ~ 99999 사이의 숫자
                if(numbercnt > 0) {
                    idx = 1;
                    numbercnt -= 1;
                    isEnd = true;
                } else {
                    idx = 2;
                }
            } else {
                if(isEnd) idx = 2;
                else idx = 0;
            }
            plus[idx] += element;
        }
    }
    // HEAD, NUMBER, TAIL 3부분으로 나누어 tuple화 시켜 vector에 저장
    tuple<string, string, string> temp(plus[0], plus[1], plus[2]);
    t.emplace_back(temp);
}

void calculateHeadNumberTail(vector<string> s, int gSize) {
    for(int i = 0; i < gSize; ++i) {
        divideStr(s[i]); // HEAD, NUMBER, TAIL 분리하는 함수
    }
}

// HEAD 부분을 기준으로 사전 순으로 정렬, 대소문자 구분하지 않음
// 대소문자 차이외에 같은 경우 NUMBER 순으로 정렬 숫자 앞의 0은 무시되고 012, 12 같은 값임
// HEAD, NUMBER 숫자도 같은 경우 입력에서 주어진 순서 유지

bool cmp(const tuple<string, string, string> t1, const tuple<string, string, string> t2) {
    string a = get<0>(t1);
    transform(a.begin(), a.end(), a.begin(), ::toupper);

    string b = get<0>(t2);
    transform(b.begin(), b.end(), b.begin(), ::toupper);
    if(a.compare(b) == 0) {
        // HEAD 같은 경우, NUMBER 순으로 정렬
        int num1 = stoi(get<1>(t1));
        int num2 = stoi(get<1>(t2));
        if(num1 == num2) {
            // NUMBER도 같다면 주어진 순서를 유지
            return false;
        } else {
            // NUMBER 같지 않을 때
            if(num1 < num2) {
                return true;
            } else {
                return false;
            }
        }
    } else {
        // HEAD 다른 경우, 사전 순으로 정렬
        return a < b;
    }
}

vector<string> solution(vector<string> files) {
    int gSize = files.size();
    calculateHeadNumberTail(files, gSize);

    // 정렬
    stable_sort(t.begin(), t.end(), cmp);
    vector<string> answer;
    for(int i = 0; i < gSize; ++i) {
        string gStr = get<0>(t[i]);
        gStr += get<1>(t[i]);
        gStr += get<2>(t[i]);
        answer.emplace_back(gStr);
    }
    return answer;
}

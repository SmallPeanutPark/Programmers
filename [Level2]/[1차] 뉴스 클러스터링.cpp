#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_LENGTH 2
#define NUMBER 65536
using namespace std;

vector<string> t1; // 분리
vector<string> t2; // 분리

vector<string> unionSet; // 합집합
vector<string> intersectionSet; // 교집합

void makeSet() {
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    set_intersection(t1.begin(), t1.end(), t2.begin(), t2.end(), back_inserter(intersectionSet));
    set_union(t1.begin(), t1.end(), t2.begin(), t2.end(), back_inserter(unionSet));
}

void makedivideSet(string s, vector<string>& v) {
    // 2글자를 끊어서 집합을 만든다.
    int len = s.length();
    string d = "";
    for(int i = 0; i < len; ++i) {
        if(isalpha(s[i])) {
            if((s[i] >= 'a') && (s[i] <= 'z')) {
                // 소문자인경우 대문자로 바꿔줌
                s[i] -= 32;
            }

            d += s[i];
            if(d.length() == MAX_LENGTH) {
                v.emplace_back(d);
                d.clear();
                d += s[i];
            }

        } else {
            if(!d.empty()) d.clear();
            continue;
        }
    }

}

int solution(string str1, string str2) {
    int answer = 0;
    makedivideSet(str1, t1);
    makedivideSet(str2, t2);
    if((t1.size() == 0) && (t2.size() == 0)) {
        answer = 1 * NUMBER;
        return answer;
    }
    
    // 합집합, 교집합 만들기
    makeSet();
    
    double result = (static_cast<double>(intersectionSet.size())) / (static_cast<double>(unionSet.size()));
    result *= NUMBER;
    answer = result;
    return answer;
}

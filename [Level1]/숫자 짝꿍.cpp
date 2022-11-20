#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<char, int> m;

void setMap(string X) {
    int gXlength = X.length();
    for(int i = 0; i < gXlength; ++i) {
        if(m.empty()) {
           m[X[i]] = 1;
        } else {
            if(m.find(X[i]) != m.end()) {
                m[X[i]] += 1;
            } else {
                m[X[i]] = 1;
            }
        }
    }
}

string solution(string X, string Y) {
    string answer = "";
    setMap(X);
    int gYlength = Y.length();
    for(int i = 0; i < Y.length(); ++i) {
        auto result = m.find(Y[i]);
        if(result != m.end()) {
            if(result->second > 0) {
                m[Y[i]] -= 1;
                answer += Y[i];
            }
        }
    }

    sort(answer.begin(), answer.end(), greater<char>());
    if(answer.empty()) return "-1";
    else {
        if(answer[0] == '0') return "0";
    }
    
    return answer;
}

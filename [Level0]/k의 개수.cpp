#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    char c = k + '0';
    for(int g = i; g <= j; ++g) {
        string s = to_string(g);
        int len = s.length();
        for(int m = 0; m < len; ++m) {
            if(s[m] == c) answer += 1;
        }
    }
    return answer;
}

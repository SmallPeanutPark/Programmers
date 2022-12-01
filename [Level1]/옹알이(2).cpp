#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> p = {"aya", "ye", "woo", "ma"};

bool distinguishStr(string str) {
    for(int i = 0; i < str.length(); ++i) {
        if(str[i] != 'z') return false;
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    int gSize = babbling.size();
    string beforeStr = "";
    for(int i = 0; i < gSize; ++i) {
        string s = babbling[i];
        string t = "";
        int gLen = babbling[i].length();
        int sLen = 0;
        beforeStr.clear();
        for(int j = 0; j < gLen; ++j) {
            t += s[j];
            sLen = t.length();
            if((sLen == 2) || (sLen == 3)) {
                if(beforeStr.compare(t) == 0) {
                    break;
                }
                
               if(t.compare(p[0]) == 0) {
                   beforeStr = p[0];
                   s.replace(s.find(p[0]), sLen, "zzz");
                   t.clear();
               } else if(t.compare(p[1]) == 0) {
                   beforeStr = p[1];
                   s.replace(s.find(p[1]), sLen, "zz");
                   t.clear();
               } else if(t.compare(p[2]) == 0) {
                   beforeStr = p[2];
                   s.replace(s.find(p[2]), sLen, "zzz");
                   t.clear();
               } else if(t.compare(p[3]) == 0) {
                   beforeStr = p[3];
                   s.replace(s.find(p[3]), sLen, "zz");
                   t.clear();
               } else {}
                
            }
            else if(sLen < 2) {
                continue;
            }
            else {
                // sLen > 3
                break;
            }
        }
        bool isSuccess = distinguishStr(s);
        if(isSuccess) answer += 1;
    }
    return answer;
}

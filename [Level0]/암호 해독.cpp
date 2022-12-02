#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    string temp = "";
    temp += 0x20;
    temp += cipher;
    for(int i = 1; i < temp.length(); ++i) {
        if(i % code == 0) answer += temp[i];
    }
    return answer;
}

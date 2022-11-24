#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    string str = to_string(num);
    char c = k + '0';
    int len = str.length();
    for(int i = 0; i < len; ++i) {
        if(str[i] == c) return i+1;
    }
    return -1;
}

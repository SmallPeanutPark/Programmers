#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int c = 0;
    while(true) {
        c = a % b;
        if(c == 0) {
            break;
        }
        a = b;
        b = c;
    }
    return b;
}


vector<int> solution(int n, int m) {
    vector<int> answer;
    if(n > m) {
        int gcdvalue = gcd(n, m);
        answer.push_back(gcdvalue);
        answer.push_back(n*m/gcdvalue);
    } else {
        int gcdvalue = gcd(m, n);
        answer.push_back(gcdvalue);
        answer.push_back(n*m/gcdvalue);
    }
    return answer;
}

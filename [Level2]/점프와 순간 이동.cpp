#include <iostream>
using namespace std;

int solution(int n) {
    int ans = 0;
    while(n != 0) {
        if(n % 2 != 0) {
            n -= 1;
            ans += 1;
        } else {
            // 순간 이동
            n /= 2;
        }
    }
    return ans;
}

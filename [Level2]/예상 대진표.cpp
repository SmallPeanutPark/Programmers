#include <iostream>

using namespace std;

int getMatch(int& a, int& b) {
    int ans = 0;
    while(true) {
        ans += 1;
        if(a % 2 == 0) {
            int result = a / 2;
            a = result;
        } else {
            int result = a / 2;
            a = result + 1;
        }
        
        if(b % 2 == 0) {
            int result = b / 2;
            b = result;
        } else {
            int result = b / 2;
            b = result + 1;
        }

        if(a < b) {
            if(a % 2 != 0) {
                if(b % 2 == 0) {
                    if((b - a - 1) == 0) {
                        ans += 1;
                        break;
                    }
                }
            }
        } else {
            // b < a
            if(b % 2 != 0) {
                if(a % 2 == 0) {
                    if((a - b - 1) == 0) {
                        ans += 1;
                        break;
                    }
                }
            }
        }
        
    }
    return ans;
}

int solution(int n, int a, int b)
{
    int answer = 0;
    if(a < b) {
        if(a % 2 != 0) {
            if(b % 2 == 0) {
                if((b - a - 1) == 0) {
                    answer += 1;
                    return answer;
                }
            }
        }
    } else {
        // b < a
        if(b % 2 != 0) {
            if(a % 2 == 0) {
                if((a - b - 1) == 0) {
                    answer += 1;
                    return answer;
                }
            }
        }
    }
    answer += getMatch(a, b);
    
    return answer;
}

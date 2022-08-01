#include <string>
#include <vector>
#include <iostream>

using namespace std;
#define MODULAR 1000000007

int dp[60001] = {0,};

int solution(int n) {
    int answer = 0;
    if(n == 1) return 1;
    if(n == 2) return 2;

    if(dp[n] != 0) return dp[n] % MODULAR;
    else {
        dp[n] = (solution(n-1) + solution(n-2)) % MODULAR;
    }
    
    return dp[n];
}

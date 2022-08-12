#include <algorithm>
#include <iostream>
#define MODULAR 1000000007
using namespace std;

long long dp[5001];

long long tiling(int n) {
    if(n % 2 != 0) return 0;
    if(dp[n] != 0) return dp[n] % MODULAR;
    else {
        long long result = (3 % MODULAR * tiling(n-2) % MODULAR);
        for(int i = 4; i <= n; i += 2) {
            result += ((2*tiling(n - i)) % MODULAR);
        }
        dp[n] = result;
    }
    return dp[n] % MODULAR;
}

long long solution(int n) {
    int answer = 0;
    fill(dp, dp + 5001, 0);
    dp[0] = 1;
    dp[2] = 3;

    return tiling(n);
}

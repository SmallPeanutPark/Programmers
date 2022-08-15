#include <string>
#include <vector>

using namespace std;
#define MODULAR 1234567

long long dp[2001];

long long recursive(int n) {
    if(dp[n] != 0) return dp[n] % MODULAR;
    else {
        return dp[n] = (recursive(n - 2) + recursive(n -1)) % MODULAR;
    }
}

long long solution(int n) {
    fill(dp, dp + 2001, 0);
    dp[1] = 1;
    dp[2] = 2;
    return recursive(n);
}

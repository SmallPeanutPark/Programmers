#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

int getNum(int num) {
    if(num == 1) return 1;
    int cnt = 1;
    for(int i = 1; i <= num / 2; ++i) {
        if(num % i == 0) {
            cnt += 1;
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    vector<int> numCnt;
    for(int i = 1; i <= number; ++i) {
        int n = getNum(i);
        numCnt.push_back(n);
    }
    for(int i = 0; i < number; ++i) {
        if(numCnt[i] > limit) numCnt[i] = power;
    }
    int answer = accumulate(numCnt.begin(), numCnt.end(), 0);
    return answer;
}

#include <string>
#include <vector>
#include <bitset>
#include <utility>
#include <cmath>
#include <iostream>
using namespace std;

vector<unsigned long long> solution(vector<long long> numbers) {
    vector<unsigned long long> answer;
    int len = numbers.size();
    for(int i = 0; i < len; ++i) {
        bitset<50> gBit(numbers[i]);
        if(numbers[i] % 2 == 0) {
            // 짝수
            gBit[0] = true;
        } else {
            for(int i = 0; i < gBit.size(); ++i) {
                if(gBit[i] == false) {
                    gBit[i] = true;
                    gBit[i - 1] == true ? gBit[i - 1] = false : gBit[i -1] = true;
                    break;
                }
            }
        }
        answer.emplace_back(gBit.to_ullong());
    }
    return answer;
}

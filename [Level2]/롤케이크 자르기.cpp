#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;
map<int, int> toppingCnt;

void setToppingCnt(vector<int> t) {
    for(int element : t) {
        toppingCnt[element] += 1;
    }
}

int solution(vector<int> topping) {
    int answer = 0;
    int len = topping.size();
    setToppingCnt(topping);
    int toppingSize = toppingCnt.size();
    map<int, int> brother;
    for(int i = 0; i < len; ++i) {
        if(toppingCnt.find(topping[i]) != toppingCnt.end()) {
            // 찾았을 때
            toppingCnt[topping[i]] -= 1;
            brother[topping[i]] += 1;
            if(toppingCnt[topping[i]] == 0) {
                toppingCnt.erase(topping[i]);
            }
        }

        if(brother.size() == toppingCnt.size()) {
            answer += 1;
        }
    }
    return answer;
}

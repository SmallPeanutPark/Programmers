#include <string>
#include <vector>
#include <map>
#include <iostream>
#define MAX_DAY 10
using namespace std;

map<string, int> want_product;

void setWantProduct(const vector<string> w, const vector<int> n) {
    // key : 상품, value : 필요한 상품의 갯수
    int gWantSize = w.size();
    for(int i = 0; i < gWantSize; ++i) {
        want_product[w[i]] = n[i];
    }
}

map<string, int> initialize(vector<string> d) {
    map<string, int> temp;
    for(int i = 0; i < MAX_DAY; ++i) {
        temp[d[i]] += 1;
    }
    return temp;
}

bool correctProduct(map<string, int> mp) {
    // wantProduct 와 비교
    for(auto iter = want_product.begin(); iter != want_product.end(); ++iter) {
        if(mp.find(iter->first) != mp.end()) {
            if(mp[iter->first] == iter->second) continue;
            else return false;
        } else return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int gWantSize = want.size();
    map<string, int> m = initialize(discount);
    setWantProduct(want, number);
    
    if(correctProduct(m)) answer += 1;

    int dSize = discount.size();
    for(int i = MAX_DAY; i < dSize; ++i) {
        m[discount[i - MAX_DAY]] -= 1;
        m[discount[i]] += 1;
        if(correctProduct(m)) answer += 1;
    }
    return answer;
}

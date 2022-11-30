#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

vector<int> box;

void setBox(vector<int>& t) {
    for(int i = 0; i < t.size(); ++i) {
        box[t[i]] += 1;
    }
}

int solution(int k, vector<int> tangerine) {
    sort(tangerine.begin(), tangerine.end(), greater<int>());
    box.resize(tangerine[0] + 1);
    setBox(tangerine);
    sort(box.begin(), box.end(), greater<int>());
    int answer = 0;
    for(int element : box) {
        if(k <= 0) break;
        answer +=1;
        k -= element;
    }
    return answer;
}

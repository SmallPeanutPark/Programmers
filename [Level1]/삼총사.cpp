#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int len = number.size();
    sort(number.begin(), number.end());
    vector<bool> selected(len, false);
    fill(selected.end() - 3, selected.end(), true);
    do {
        int ans = 0;
        for(int i = 0; i < len; ++i) {
            if(selected[i] == true) {
                ans += number[i];
            }
        }
        if(ans == 0) answer += 1;
        
    } while(next_permutation(selected.begin(), selected.end()));

    return answer;
}

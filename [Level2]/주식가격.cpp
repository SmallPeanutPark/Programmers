#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int len = prices.size();

    for (int k = 0; k < len; ++k) {
        int time = 0;
        for (int m = k+1; m < len; ++m) {
            if (prices[k] <= prices[m]) {
                time += 1;
            }
            else {
                time += 1;
                break;
            }
        }
        answer.push_back(time);
    }

    return answer;
}

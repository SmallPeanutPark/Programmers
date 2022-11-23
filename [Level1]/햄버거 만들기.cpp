#include <string>
#include <vector>
#include <algorithm>

#define BUGGER_SIZE 4
using namespace std;

string order = "1231";

int solution(vector<int> ingredient) {
    int answer = 0;
    string bugger = "";
    int buggerSize = 0;
    int len = ingredient.size();
    for(int i = 0; i < len; ++i) {
        bugger += to_string(ingredient[i]);
        buggerSize = bugger.length();
        if(buggerSize >= BUGGER_SIZE) {
            if(order.compare(bugger.substr(buggerSize - BUGGER_SIZE, BUGGER_SIZE)) == 0) {
                bugger.erase(buggerSize - BUGGER_SIZE, BUGGER_SIZE);
                answer += 1;
            }
        }
    }
    return answer;
}

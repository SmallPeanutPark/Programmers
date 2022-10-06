#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> ans;
    for(string str : strlist) {
        ans.emplace_back(str.length());
    }
    return ans;
}

#include <string>
#include <vector>
#include <utility>
using namespace std;

vector<int> solution(vector<int> num_list) {
    pair<int, int> gEvenOdd = {0, 0};
    for(int element : num_list) {
        if(element % 2 == 0) gEvenOdd.first += 1;
        else gEvenOdd.second += 1;
    }
    vector<int> ans;
    ans.push_back(gEvenOdd.first);
    ans.push_back(gEvenOdd.second);
    return ans;
}

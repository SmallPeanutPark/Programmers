#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    for(int element : numlist) {
        if(element % n == 0) answer.push_back(element);
        else continue;
    }
    return answer;
}

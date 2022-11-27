#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    map<int, int> m;
    for(int i = 0; i < array.size(); ++i) {
        m[array[i]] += 1;
    }
    
    int maxSecond = 0;
    for(auto iter = m.begin(); iter != m.end(); ++iter) {
       if(maxSecond < (iter->second)) {
           maxSecond = iter->second;
           answer = iter->first;
       } else if(maxSecond == iter->second) {
           answer = -1;
       } else {}
    }
    return answer;
}

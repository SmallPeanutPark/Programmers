#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    vector<string> s;
    for(int i = 0; i < array.size(); ++i) {
        s.emplace_back(to_string(array[i]));
    }

    for(int i = 0; i < array.size(); ++i) {
        string s1 = s[i];
        for(int j = 0; j < s1.length(); ++j) {
            if(s1[j] == '7') answer += 1;
        }
    }
    
    
    return answer;
}

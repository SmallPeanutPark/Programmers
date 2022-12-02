#include <string>
#include <vector>

using namespace std;

vector<char> c = {'3', '6', '9'};

int solution(int order) {
    string s = to_string(order);
    int answer = 0;
    for(int i = 0; i < s.length(); ++i) {
        if((s[i] == c[0]) || (s[i] == c[1]) || (s[i] == c[2])) {
            answer += 1;
        } 
    }
    return answer;
}

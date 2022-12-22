#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string my_string) {
    string answer = "";
    map<char, int> m;
    for(char element : my_string) {
        m[element] += 1;
        if(m[element] >= 2) continue;
        else answer += element;
    }
    
    return answer;
}

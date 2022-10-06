#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string ans = "";
    for(auto element : my_string) {
        if(element == 'a' || element == 'e' || element == 'i' || element == 'o' || element == 'u') continue;
        else ans += element;
    }
    return ans;
}

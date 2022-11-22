#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    int copy_n = n;
    for(int i = 0; i < my_string.length(); ++i) {
        while(copy_n != 0) {
            answer += my_string[i];
            copy_n -= 1;
        }
        copy_n = n;
    }
    return answer;
}

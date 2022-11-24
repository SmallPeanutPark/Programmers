#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, string letter) {
    string str = "";
    for(int i = 0; i < my_string.length(); ++i) {
        if(my_string[i] == letter[0]) continue;
        str += my_string[i];
    }
    return str;
}

#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), greater<char>());
    answer = s;
    return answer;
}

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<string> checkString = { "zero", "one", "two", "three", "four", "five", "six", "seven",
                                  "eight", "nine"};

    int len = s.length();

    string tempStr = "";
    string ans = "";
    for (int i = 0; i < len; ++i) {
        if (isalpha(s[i])) {
            // 알파벳일 때
            tempStr += s[i];
            if (tempStr.length() > 2) {
                for (int j = 0; j < 10; ++j) {
                    if (checkString[j].compare(tempStr) == 0) {
                        // 같을 때
                        ans += to_string(j);
                        tempStr.clear();
                        break;
                    }
                }
            }
        }
        else {
            // 알파벳이 아닐 때
            ans += s[i];
        }
    }
    int answer = stoi(ans);
    return answer;
}

#include <string>
#include <vector>

using namespace std;

vector<string> s = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<char> num = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

long long solution(string numbers) {
    long long answer = 0;
    string result = "";
    string str = "";
    for(int i = 0; i < numbers.length(); ++i) {
        str += numbers[i];
        int glen = str.length();
        if(glen >= 3) {
            if(str.compare(s[0]) == 0) {
                result += num[0];
                str.clear();
            } else if(str.compare(s[1]) == 0) {
                result += num[1];
                str.clear();
            } else if(str.compare(s[2]) == 0) {
                result += num[2];
                str.clear();
            } else if(str.compare(s[3]) == 0) {
                result += num[3];
                str.clear();
            } else if(str.compare(s[4]) == 0) {
                result += num[4];
                str.clear();
            } else if(str.compare(s[5]) == 0) {
                result += num[5];
                str.clear();
            } else if(str.compare(s[6]) == 0) {
                result += num[6];
                str.clear();
            } else if(str.compare(s[7]) == 0) {
                result += num[7];
                str.clear();
            } else if(str.compare(s[8]) == 0) {
                result += num[8];
                str.clear();
            } else if(str.compare(s[9]) == 0) {
                result += num[9];
                str.clear();
            } else {}
        }
    }
    answer = stoll(result);
    return answer;
}

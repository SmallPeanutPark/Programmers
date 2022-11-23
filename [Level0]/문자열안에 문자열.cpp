#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    auto result = str1.find(str2);
    if(result != string::npos) return 1;
    else return 2;
}

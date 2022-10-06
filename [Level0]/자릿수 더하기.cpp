#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int ans = 0;
    string gStr = to_string(n);
    for(int i = 0; i < gStr.length(); ++i) {
        ans += gStr[i] - '0';
    }
    return ans;
}

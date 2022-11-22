#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int getdrink = n / 10;
    k -= getdrink;
    int answer = ((12000 * n) + (2000 * k));
    return answer;
}

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n / 7;
    if(n % 7 != 0) answer += 1;
    return answer;
}

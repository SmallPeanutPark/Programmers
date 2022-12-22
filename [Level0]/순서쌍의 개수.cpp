#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    if(n % 2 == 0) {
        for(int i = 1; i <= n/2; ++i) {
            if(n % i == 0) {
                answer += 1;
            }
        }
        answer += 1;
    } else {
        for(int i = 1; i <= n; ++i) {
            if(n % i == 0) {
                answer += 1;
            }
        }
    }
    return answer;
}

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        if(i % 2 == 0) sum += i;
    }
    return sum;
}

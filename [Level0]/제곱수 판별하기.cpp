#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int num = sqrt(n);
    if((num * num) == n) return 1;
    else return 2;
}

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int cnt = 0;
    for(int element : array) {
        if(element == n) cnt += 1;
    }
    return cnt;
}

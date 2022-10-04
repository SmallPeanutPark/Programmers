#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int ans = 0;
    for(int i = 0; i < array.size(); ++i) {
        if(array[i] > height) ans += 1;
    }
    return ans;
}

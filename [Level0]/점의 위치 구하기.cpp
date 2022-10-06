#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    pair<int, int> d = {dot[0], dot[1]};
    if(d.first > 0) {
        if(d.second > 0) return 1;
        else return 4;
    } else {
        if(d.second > 0) return 2;
        else return 3;
    }
}

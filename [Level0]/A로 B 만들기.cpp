#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> before_map;
map<char, int> after_map;

int solution(string before, string after) {
    for(char element : before) {
        before_map[element] += 1;
    }
    
    for(char element : after) {
        after_map[element] += 1;
    }
    
    if(before_map == after_map) {
        return 1;
    } else {
        return 0;
    }
}

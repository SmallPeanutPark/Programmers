#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#define CACHE_HIT 1
#define CACHE_MISS 5
using namespace std;
list<string> li;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for(string element : cities) {
        if(cacheSize == 0) {
            answer += CACHE_MISS;
            continue;
        } else {
            transform(element.begin(), element.end(), element.begin(), ::toupper);
            auto result = find(li.begin(), li.end(), element);
            if(li.size() < cacheSize) {
                if(result != li.end()) {
                    li.erase(result);
                    li.push_back(element);
                    answer += CACHE_HIT;
                } else {
                    li.push_back(element);
                    answer += CACHE_MISS;
                }
            } else {
                if(result != li.end()) {
                    li.erase(result);
                    li.push_back(element);
                    answer += CACHE_HIT;
                } else {
                    li.pop_front();
                    li.push_back(element);
                    answer += CACHE_MISS;
                }
            }
        }
    }
    return answer;
}

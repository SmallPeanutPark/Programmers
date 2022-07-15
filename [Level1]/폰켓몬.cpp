#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> m;
    sort(nums.begin(), nums.end());
    int len = nums.size();

    for (int i = 0; i < len; ++i) {
        auto iter = m.find(nums[i]);
        if (iter != m.end()) {
            iter->second += 1;
        }
        else {
            m.insert(make_pair(nums[i], 1));
        }
    }
    // len/2 을 뽑을 때 많은 종류의 폰켓몬을 뽑는 경우?
    int mlen = m.size();
    if (len / 2 > mlen) {
        answer = m.size();
    }
    else {
        int diff = mlen - (len / 2);
        answer = m.size() - diff;
    }
    
    return answer;
}

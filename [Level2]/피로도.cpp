#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int result = 0;
    int len = dungeons.size();
    sort(dungeons.begin(), dungeons.end());
    do {
        int temp = k;
        int answer = 0;
        for (int i = 0; i < len; ++i) {
            if (dungeons[i][0] <= temp) {
                temp -= dungeons[i][1];
                answer += 1;
            }
        }
        result = max(result, answer);
    } while (next_permutation(dungeons.begin(), dungeons.end()));
    return result;
}

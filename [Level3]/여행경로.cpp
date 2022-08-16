#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<bool> visited;
vector<string> answer;
int len;

bool dfs(string cur, vector<vector<string>>& t, int usedtickets) {
    // 탈출 조건 필요
    if (usedtickets == len) {
        return true;
    }

    for (int i = 0; i < len; ++i) {
        if (visited[i]) continue;
        if (cur.compare(t[i][0]) == 0) {
            visited[i] = true;
            answer.emplace_back(t[i][1]);
            bool isresult = dfs(t[i][1], t, usedtickets + 1);
            if (!isresult) {
                visited[i] = false;
                answer.pop_back();
            }
            else return true;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    len = tickets.size();
    visited.resize(len);
    sort(tickets.begin(), tickets.end());
    fill(visited.begin(), visited.end(), false);
    answer.emplace_back("ICN");
    dfs("ICN", tickets, 0);
    for (string element : answer) {
        cout << element << ' ';
    }
    return answer;
}

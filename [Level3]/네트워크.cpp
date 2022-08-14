#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> graph[201];
bool visited[201];

void dfs(int cur) {
    visited[cur] = true;

    for(int element : graph[cur]) {
        if(visited[element]) continue;
        dfs(element);
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int rowlen = computers.size();
    int columnlen = computers[0].size();
    for(int i = 0; i < rowlen; ++i) {
        for(int j = 0; j < columnlen; ++j) {
            if(computers[i][j] == 1)
                graph[i].emplace_back(j);
        }
    }

    for(int i = 0; i < n; ++i) {
        if(visited[i]) continue;
        answer += 1;
        dfs(i);
    }
    return answer;
}

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> graph[20001];
int dist[20001];
int maxdist;

void bfs(int cur) {
    queue<int> q;
    q.push(cur);
    dist[cur] = 0;
    while(!q.empty()) {
        int curlocation = q.front();
        q.pop();
        for(int element : graph[curlocation]) {
            if(dist[element] >= 0) continue;
            q.push(element);
            dist[element] = dist[curlocation] + 1;
            maxdist = max(maxdist, dist[element]);
        }
    }
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    maxdist = 0;
    int rowlen = edge.size();
    fill(dist, dist + 20001, -1);
    for(int i = 0; i < rowlen; ++i) {
        for(int j = 0; j < 1; ++j) {
            graph[edge[i][0]].emplace_back(edge[i][1]);
            graph[edge[i][1]].emplace_back(edge[i][0]);
        }
    }

    bfs(1);
    for(int i = 1; i <= n; ++i) {
        if(dist[i] == maxdist) {
            answer += 1;
        }
    }
    return answer;
}

int main(void) {
    int n = 6;
    vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    solution(n, edge);
}

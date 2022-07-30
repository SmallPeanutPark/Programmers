#include<vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int dist[101][101];
bool visited[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int solution(vector<vector<int> > maps)
{
    // 0: 벽, 1: 벽 없음
    int answer = 0;
    
    for (int i = 0; i < 101; ++i) {
        fill(dist[i], dist[i] + 101, -1);
    }

    // 적 위치
    int nsize = maps.size() - 1;
    int msize = maps[0].size() - 1;

    queue<pair<int, int>> q;
    // 처음 캐릭터 위치, 방문 여부 확인
    q.push({ 0,0 });
    dist[0][0] = 1;
    visited[0][0] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            // 다음 위치
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx > nsize || ny < 0 || ny > msize) continue;
            if ((maps[nx][ny] == 0) || (visited[nx][ny] == true)) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
    answer = dist[nsize][msize];
    cout << answer;
    return answer;
}

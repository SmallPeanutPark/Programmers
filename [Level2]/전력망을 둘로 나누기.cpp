#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int rowlen;
int N;
set<int> arr[101];
bool visited[101];

int bfs(int cur) {
    int count = 0;
    queue<int> q;
    q.push(cur);
    visited[cur] = true;
    while (!q.empty()) {
        int curlocation = q.front();
        q.pop();
        count += 1;
        for (int element : arr[curlocation]) {
            if (visited[element]) continue;
            q.push(element);
            visited[element] = true;
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int minvalue = n;
    rowlen = wires.size();
    N = n;

    // 맵 세팅
    for (int i = 0; i < rowlen; ++i) {
        int row = wires[i][0];
        int column = wires[i][1];
        arr[row].insert(column);
        arr[column].insert(row);
    }
    
    for (int i = 0; i < rowlen; ++i) {        
        fill(visited, visited + 101, false);
        int disA = wires[i][0];
        int disB = wires[i][1];

        // 연결 끊기
        arr[disA].erase(disB);
        arr[disB].erase(disA);
        
        minvalue = min(minvalue, abs(bfs(disA) - bfs(disB)));

        // 재연결
        arr[disA].insert(disB);
        arr[disB].insert(disA);
    }
    cout << minvalue;
    return minvalue;
}

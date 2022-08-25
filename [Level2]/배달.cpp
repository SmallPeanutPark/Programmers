#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define INF 1e9

vector<pair<int, int>> city[51];
vector<int> gtime;

void dijkstra(int cur) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, cur});
    gtime[cur] = 0;
    while(!pq.empty()) {
        int cur_city = pq.top().second;
        int cur_time = pq.top().first;
        pq.pop();
        for (pair<int, int> element : city[cur_city]) {
            int next_city = element.first;
            int next_time = element.second + cur_time;
            if (next_time < gtime[next_city]) {
                gtime[next_city] = next_time;
                pq.push({ next_time, next_city });
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    int rowlen = road.size();
    gtime.resize(N + 1, INF);


    for (int i = 0; i < rowlen; ++i) {
        int startcity = road[i][0];
        int endcity = road[i][1];
        int time = road[i][2];
        city[startcity].emplace_back(make_pair(endcity, time));
        city[endcity].emplace_back(make_pair(startcity, time));
    }

    dijkstra(1);
    for (int i = 1; i <= N; ++i) {
        if (K >= gtime[i]) answer += 1;
    }

    return answer;
}

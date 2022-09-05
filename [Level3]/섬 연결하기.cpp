#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[2] < v2[2];
}

int getParent(vector<int>& parent, int island) {
    if(parent[island] == island) return island;
    else return parent[island] = getParent(parent, parent[island]);
}

void unionParent(vector<int>& parent, int island1, int island2) {
    island1 = getParent(parent, island1);
    island2 = getParent(parent, island2);

    if(island1 == island2) return;

    if(island1 < island2) parent[island2] = island1;
    else parent[island1] = island2;
}

bool findParent(vector<int>& parent, int island1, int island2) {
    island1 = getParent(parent, island1);
    island2 = getParent(parent, island2);

    if(island1 == island2) return true;
    else return false;
}

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), cmp); // 비용 오름 차순 정렬
    vector<int> parent(n + 1);
    for(int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int rowlen = costs.size();
    int gCost = 0;
    for(int i = 0; i < rowlen; ++i) {
        if(findParent(parent, costs[i][0], costs[i][1]) == false) {
            gCost += costs[i][2];
            unionParent(parent, costs[i][0], costs[i][1]);
        }
    }
    return gCost;
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int sizes_len = sizes.size();
    int vec_sizes_len = sizes[0].size();

    for (int i = 0; i < sizes_len; ++i) {
        sort(sizes[i].begin(), sizes[i].end());
    }

    vector<int> row;
    vector<int> column;

    for (int i = 0; i < sizes_len; ++i) {
        for (int j = 0; j < vec_sizes_len; ++j) {
            if (j == 0) {
                row.push_back(sizes[i][0]);
            }
            else {
                column.push_back(sizes[i][1]);
            }
        }
    }

    int max_row = *max_element(row.begin(), row.end());
    int max_column = *max_element(column.begin(), column.end());

    answer = max_row * max_column;

    return answer;
}

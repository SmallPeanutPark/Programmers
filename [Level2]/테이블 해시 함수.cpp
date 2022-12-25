#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int column;

bool cmp(const vector<int>& v1, const vector<int>& v2) {
    if(v1[column] == v2[column]) {
        return v1[0] > v2[0] ? true : false;
    } else {
        return v1[column] < v2[column] ? true : false;
    }
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col - 1;
    /*
    테이블의 튜플을 col번째 컬럼의 값을 기준으로 오름차순 정렬을 하되, 
    만약 그 값이 동일하면 기본키인 첫 번째 컬럼의 값을 기준으로 내림차순 정렬합니다.
    */
    sort(data.begin(), data.end(), cmp);
    /*
    정렬된 데이터에서 S_i를 i 번째 행의 튜플에 대해 
    각 컬럼의 값을 i 로 나눈 나머지들의 합으로 정의합니다.
    */
    int len = data[0].size();
    for(int i = row_begin; i <= row_end; ++i) {
        int totalSum = 0;
        for(int j = 0; j < len; ++j) {
            totalSum += (data[i - 1][j] % i);
        }
        answer ^= totalSum;
    }
    
    return answer;
}

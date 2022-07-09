#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> temp;
    int length = arr1.size(); // 행
    int length2 = arr1[0].size(); // 열
    int result;
    
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length2; ++j)
        {
            result = arr1[i][j] + arr2[i][j];
            temp.push_back(result);
        }
        answer.push_back(temp);
        temp.clear();
    }
    return answer;
}

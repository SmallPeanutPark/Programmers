#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer; // 가로, 세로

    int plus = brown + yellow; 
    //약수를 구하라
    map<int, int> m; // 중복 허용 X, 가로 >= 세로일 때만 저장
    for (int i = 1; i <= plus; ++i) {
        int num = plus / i;
        
        // 큰 값이 가로, 몫이 크거나 같을 떄만
        if (num >= i)
            m.insert(make_pair(num, i));
    }

    map<int, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter) {
        int row = (iter->first) * 2;
        int column = ((iter->second) * 2) - 4;
        if ((row + column == brown) && (column > 0) &&
           (((iter->first -2) * (iter->second -2)) == yellow)) {
            answer.push_back(iter->first);
            answer.push_back(iter->second);
            break;
        }

    }
    return answer;
}

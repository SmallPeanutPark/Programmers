#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;

    string str = to_string(n);

    for (int i = str.length() -1 ; i >= 0; --i)
    {
        int temp = str[i] - '0';
        answer.push_back(temp);
    }

    return answer;
}

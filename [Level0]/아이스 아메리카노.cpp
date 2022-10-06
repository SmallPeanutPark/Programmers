#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer;
    int num = 0;
    num = money / 5500;
    answer.push_back(num);
    money -= (num * 5500);
    answer.push_back(money);
    return answer;
}

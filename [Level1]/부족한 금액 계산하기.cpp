#include <string>
#include <vector>

using namespace std;

long long solution(int price, int money, int count)
{
    long long need_money = 0; // 부족하지 않다면 0을 return


    long long total_money = 0;
    for (int i = 1; i <= count; ++i) {
        total_money += price * i;
    }

    if (total_money > money) {
        // 최종 필요한 금액 > 가진 금액
        need_money = total_money - money;
    }
    else {
        // 최종 필요한 금액 < 가진 금액 또는 최종 필요한 금액 == 가진 금액
        // need_money = 0임
    }

    return need_money;
}

#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    int answer = 0;
    if(price >= 500000) {
        // 20% discount
        double d = static_cast<double>(price) * 0.2;
        price -= d;
        answer = price;
    } else if(price >= 300000) {
        // 10% discount
        double d = static_cast<double>(price) * 0.1;
        price -= d;
        answer = price;
    } else if(price >= 100000) {
        // 5% discount
        double d = static_cast<double>(price) * 0.05;
        price -= d;
        answer = price;
    } else {
        answer = price;
    }
    return answer;
}

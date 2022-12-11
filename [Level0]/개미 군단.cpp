#include <string>
#include <vector>

using namespace std;

int ant[3] = {5, 3, 1};

int solution(int hp) {
    int answer = hp / ant[0];
    hp %= ant[0];
    answer += hp / ant[1];
    hp %= ant[1];
    answer += hp / ant[2];
    hp /= ant[2];
    return answer;
}

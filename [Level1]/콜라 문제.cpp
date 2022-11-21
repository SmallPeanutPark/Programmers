#include <string>
#include <vector>
using namespace std;

int calculateCokeBottle(int emptyCokeBottle, int giveCokeBottle, int haveEmptyCokeBottle) {
    int totalCoke = 0;
    while(haveEmptyCokeBottle >= emptyCokeBottle) {
        int cokebottle = haveEmptyCokeBottle / emptyCokeBottle;
        totalCoke += (cokebottle * giveCokeBottle);
        haveEmptyCokeBottle = haveEmptyCokeBottle % emptyCokeBottle;
        haveEmptyCokeBottle += (cokebottle * giveCokeBottle);
    }

    return totalCoke;
}

int solution(int a, int b, int n) {
    int answer = calculateCokeBottle(a, b, n);
    return answer;
}

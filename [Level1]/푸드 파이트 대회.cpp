#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string setFirstPlayer(vector<int>& depolymentfood) {
    int gfoodlength = depolymentfood.size();
    string firstPlayer = "";
    for(int i = 1; i < gfoodlength; ++i) {
        int cnt = depolymentfood[i] / 2;
        while(cnt != 0) {
            firstPlayer += (i + '0');
            cnt -= 1;
        }
    }
    return firstPlayer;
}

string solution(vector<int> food) {
    string firstPlayer = setFirstPlayer(food);
    string secondPlayer = firstPlayer;
    reverse(secondPlayer.begin(), secondPlayer.end());
    firstPlayer += '0';
    firstPlayer += secondPlayer;
    return firstPlayer;
}

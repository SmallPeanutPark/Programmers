#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int getGCD(vector<int>& arr) {
    int num1 = arr[0];
    for(int i = 1; i < arr.size(); ++i) {
        int num2 = arr[i];
        while(true) {
            int num3 = num2 % num1;
            if(num3 == 0) {
                break;
            }
            num2 = num1;
            num1 = num3;
        }
    }
    return num1;
}


int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    int gAnum = getGCD(arrayA); 
    int gBnum = getGCD(arrayB);

    answer = max(gAnum, gBnum);
    if(answer == gAnum) {
        for(int element : arrayB) {
            if(element % answer == 0) return 0;
        }
    } else {
        for(int element : arrayA) {
            if(element % answer == 0) return 0;
        }
    }

    return answer;
}

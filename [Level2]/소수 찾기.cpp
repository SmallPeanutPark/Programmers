#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000000] = { 0, };

bool isPrime(int number) {

    if (number < 2) {
        return false;
    }

    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false; // 소수 아님
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int len = numbers.length();
    vector<int> numvector;
    for (int i = 0; i < len; ++i) {
        numvector.push_back(numbers[i] - '0');
    }
    sort(numvector.begin(), numvector.end());

    for (int i = 1; i <= len; ++i) {
        vector<bool> temp(len - i, false);
        temp.insert(temp.end(), i, true);
        do {
            string s;
            for (int j = 0; j < len; ++j) {
                if (temp[j]) {
                    s += to_string(numvector[j]);
                    cout << numvector[j];
                }
            }
            cout << '\n';
            int slength = s.length();
            if (slength == 1) {
                if (arr[s[0] - '0'] == 0) {
                    if (isPrime(s[0] - '0')) {
                        ++answer;
                        arr[s[0] - '0']++;
                    }
                }
            }
            else {
                if (arr[stoi(s)] == 0) {
                    if (isPrime(stoi(s))) {
                        ++answer;
                        arr[stoi(s)]++;
                    }
                }
            }

        } while (next_permutation(numvector.begin(), numvector.end()));
    }
    cout << answer;
    return answer;
}

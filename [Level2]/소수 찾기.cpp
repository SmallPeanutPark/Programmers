#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000000] = { 0, }; // 중복 값을 확인하기 위한 배열

bool isPrime(int number) {

    if (number < 2) {
        return false; // 소수 아님
    }

    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false; // 소수 아님
        }
    }
    return true; // 소수임
}

int solution(string numbers) {
    int answer = 0;
    int len = numbers.length();
    vector<int> numvector; // 문자를 숫자로 바꾸기 위한 vector
    for (int i = 0; i < len; ++i) {
        numvector.push_back(numbers[i] - '0');
    }
    sort(numvector.begin(), numvector.end()); // 오름 차순 정렬
    
    // 자릿수 때문에 do-while문 위에 for문 사용
    // 아래와 같이 사용하면 1자리부터 len 자리수까지 순열을 구할 수 있다.
    for (int i = 1; i <= len; ++i) {
        vector<bool> temp(len - i, false);
        temp.insert(temp.end(), i, true);
        do {
            string s;
            for (int j = 0; j < len; ++j) {
                if (temp[j]) {
                    s += to_string(numvector[j]);
                }
            }
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
    return answer;
}

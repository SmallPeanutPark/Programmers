#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    /*
    첫째 자리 : 781
    둘째 자리 : 156
    셋째 자리 : 31
    넷째 자리 : 6
    다섯째 자리 : 1
    */
    int arr[5] = { 781, 156, 31, 6, 1 };
    char value[5] = { 'A', 'E', 'I', 'O', 'U' }; // 0 , 1, 2, 3, 4

    int len = word.size();
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (word[i] == value[j]) {
                answer += (1 + (arr[i] * j));
                break;
            }
        }
    }
    return answer;
}

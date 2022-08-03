#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    fill(answer.begin(), answer.end(), 0);
    map<string, int> m;
    int people = 0;
    int cycle = 1;
    int wlen = words.size();

    for (int i = 0; i < wlen; ++i) {

        // 사람들이 단어 외침
        if (people == n) {
            people = 0;
            cycle += 1;
        }

        people += 1; // 단어 말함

        if (m.empty()) {
            // 초기
            m.insert({ words[i], 0 });
        }
        else {
            // 이후
            // 앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말해야 합니다.
            int comparelen = words[i - 1].length(); // 문자 길이 구하고
            string comparestr = words[i - 1].substr(comparelen - 1); // 마지막 문자를 확인한다.
            
            // 현재 문자의 앞문자와 앞사람의 마지막 문자로 시작하는지 확인한다.
            string str = words[i];
            if (str[0] == comparestr[0]) {
                if (m.find(words[i]) != m.end()) {
                    // 중복된 단어 말한 경우
                    // [0]번호, [1]차례
                    answer[0] = people;
                    answer[1] = cycle;
                    break;
                }
                else {
                    // 중복된 단어를 말하지 않은 경우
                    m.insert({ words[i], 0 });
                }
            }
            else {
                // 마지막 문자로 시작 안한경우
                answer[0] = people;
                answer[1] = cycle;
                break;
            }
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> score = {0, 3, 2, 1, 0, 1, 2, 3};
vector<string> personalitytype = {"RT", "CF", "JM", "AN"};
map<char, int> totalScore;

void initTotalScore() {
    for(string s : personalitytype) {
        totalScore[s[0]] = 0;
        totalScore[s[1]] = 0;
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    initTotalScore();
    int len = survey.size();
    for(int i = 0; i < len; ++i) {
        string s = survey[i];
        char firsttype = s[0];
        char secondtype = s[1];
        if((1<= choices[i]) && (choices[i] <= 3)) {
            totalScore[firsttype] += score[choices[i]];
        } else if(4 == choices[i]) {
            // nothing
        } else {
            // 5 <= choices[i] && choices[i] >= 7
            totalScore[secondtype] += score[choices[i]];
        }
    }  
    int plen = personalitytype.size();
    for(int i = 0; i < plen; ++i) {
        char t1 = personalitytype[i][0];
        char t2 = personalitytype[i][1];
        
        if(totalScore[t1] > totalScore[t2]) answer += t1;
        else if(totalScore[t1] < totalScore[t2]) answer += t2;
        else {
            // ==
            if(t1 > t2) answer += t2;
            else answer += t1;
        }
        
    }
    return answer;
}

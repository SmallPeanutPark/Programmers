#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string, int> gNameToYearn;

void setNameToYearning(vector<string> name, vector<int> yearning, int len) {
    for(int i = 0; i < len; ++i) {
        gNameToYearn[name[i]] = yearning[i];
    }
}

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int len = name.size();
    setNameToYearning(name, yearning, len);

    int photoRow = photo.size();
    for(int i = 0; i < photoRow; ++i) {
        int plusNum = 0;
        for(string element : photo[i]) {
            if(gNameToYearn.find(element) != gNameToYearn.end()) {
                // 찾음
                plusNum += gNameToYearn[element]; 
            }
        }
        if(plusNum != 0) {
            answer.emplace_back(plusNum);
        } else {
            answer.emplace_back(0);
        }
    }
    return answer;
}

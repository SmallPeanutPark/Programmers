#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<char, int> skillorder;

void setSkillOrder(string s, int len) {
    // 스킬 순서를 기록한다. 1번째부터 시작
    for(int i = 0; i < len; ++i) {
        skillorder[s[i]] = (i + 1);
    }
}

int getEnableSkillTrees(vector<string> skill_trees, int cur) {
    int gSize = skill_trees.size();
    int count = 0;
    for(int i = 0; i < gSize; ++i) {
        string s = skill_trees[i];
        int len = s.length();
        int skill_idx = 1;
        bool isfind = false;
        bool isnot = false;
        for(int j = 0; j < len; ++j) {
            if(skillorder.find(s[j]) != skillorder.end()) {
                // 스킬을 찾음 -> 순서 맞는지 확인
                isfind = true;
                if(skill_idx == skillorder[s[j]]) {
                    skill_idx += 1;
                } else {
                    isnot = true;
                    break;
                }
            } else {
                // 선행 스킬에 해당되지 않는 경우
            }
        }

        if(isfind && (!isnot)) {
            count += 1;
        }

        if(!isfind) {
            // 스킬트리가 선행스킬로 이루어지지 않은 경우
            count += 1;
        }
    }
    return count;
}

int solution(string skill, vector<string> skill_trees) {
    int len = skill.length();
    setSkillOrder(skill, len);
    int answer = getEnableSkillTrees(skill_trees, len);
    return answer;
}

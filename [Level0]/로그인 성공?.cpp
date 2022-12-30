#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, string> m;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    m[id_pw[0]] = id_pw[1];
    for(int i = 0; i < db.size(); ++i) {
        auto iter = m.find(db[i][0]);
        if(iter != m.end()) {
            if(iter->second.compare(db[i][1]) == 0) {
                answer += "login";
            } else {
                answer += "wrong pw";
            }
            return answer;
        }
    }
    answer += "fail";
    return answer;
}

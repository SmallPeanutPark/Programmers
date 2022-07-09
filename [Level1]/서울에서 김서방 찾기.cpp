#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    vector<string>::iterator viter;

    viter = find(seoul.begin(), seoul.end(), "Kim");
    int vpos = viter - seoul.begin();
    string pos = to_string(vpos);
    
    answer = "김서방은 ";
    answer.append(pos);
    answer.append("에 있다");


    return answer;
}

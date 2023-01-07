#include <string>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;
map<char, int> term_map;
vector<tuple<int, int, int>> privacy_tuple;
tuple<int, int, int> today_tuple;

void initToday(string t) {
    char findValue = '.';
    int cnt = 0;
    vector<int> tempvector;
    while(cnt < 3) {
            cnt += 1;
            auto idx = t.find(findValue);
            string s = t.substr(0, idx);
            tempvector.emplace_back(stoi(s));
            t = t.substr(idx + 1, t.length() - s.length());   
    }
    today_tuple = make_tuple(tempvector[0], tempvector[1], tempvector[2]);
}

void initTerms(vector<string> t) {
   for(string element : t) {
        stringstream stream(element);
        char alpha; int num;
        stream >> alpha;
        stream >> num;
        term_map[alpha] = num;
   }
}

void initPrivacies(vector<string> p) {
    for(string element : p) {
        int cnt = 0;
        string tempstr = element;
        char findValue = '.';
        vector<int> tempvector;
        while(cnt < 3) {
            cnt += 1;
            auto idx = element.find(findValue);
            string s = element.substr(0, idx);
            tempvector.emplace_back(stoi(s));
            element = element.substr(idx + 1, element.length() - s.length());   
        }
        // 인덱스 0 : 년, 1 : 월, 2 : 일
        int addmonth = term_map[tempstr[tempstr.length() - 1]];
        int totalmonth = tempvector[1] + addmonth;
        if(totalmonth > 12) {
            tempvector[0] += (totalmonth / 12);
            if(totalmonth % 12 == 0) {
                tempvector[0] -= 1;
                tempvector[1] = 12;
            } else {
                tempvector[1] = totalmonth % 12;
            }
        } else {
            tempvector[1] = totalmonth;
        }

        if(tempvector[2] == 1) {
            tempvector[1] -= 1;
            tempvector[2] = 28;
            if(tempvector[1] == 0) {
                tempvector[0] -= 1;
                tempvector[1] += 12;
            }
        } else {
            tempvector[2] -= 1;
        }
        tuple<int, int, int> t(tempvector[0], tempvector[1], tempvector[2]);
        privacy_tuple.emplace_back(t);
    }
}

vector<int> calprivacy() {
    int len = privacy_tuple.size();
    vector<int> ans;
    for(int i = 0; i < len; ++i) {
        tuple<int, int, int> t = privacy_tuple[i];
        int year = get<0>(t);
        int month = get<1>(t);
        int day = get<2>(t);

        if(year < get<0>(today_tuple)) {
            ans.emplace_back(i+1);
        } else if(year == get<0>(today_tuple)) {
            if(month < get<1>(today_tuple)) {
                ans.emplace_back(i+1);
            } else if(month == get<1>(today_tuple)) {
                if(day < get<2>(today_tuple)) {
                    ans.emplace_back(i+1);
                }
            } else {
                // nothing
            }
        } else {
            // nothing
        }
    }
    return ans;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    initToday(today);
    initTerms(terms);
    initPrivacies(privacies);
    answer = calprivacy();
    return answer;
}

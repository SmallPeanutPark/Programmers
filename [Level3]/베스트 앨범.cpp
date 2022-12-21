#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
multimap<string, pair<int, int>> genresTime; // 각 장르 시간 따로 따로 저장 value의 first는 재생 시간, second는 고유 번호저장
map<string, int> totalgenresTime; // 같은 장르 시간 누적 저장
/*
속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
각 장르당 2개만
*/
void initialize(int len, vector<string> g, vector<int> p) {
    for(int i = 0; i < len; ++i) {
        string str = g[i];
        totalgenresTime[str] += p[i];
        genresTime.insert(make_pair(str, make_pair(p[i], i)));
    }
}

bool cmp(const pair<string, int> p1, const pair<string, int> p2) {
    return p1.second > p2.second;
}

vector<pair<string, int>> case1() {
    // 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
    // map to vector
    vector<pair<string, int>> temp;
    for(auto iter = totalgenresTime.begin(); iter != totalgenresTime.end(); ++iter) {
        temp.emplace_back(make_pair(iter->first, iter->second));
    }
    // 많이 재생된 장르 내림차순 정렬 : 큰 값이 앞에 옴
    sort(temp.begin(), temp.end(), cmp);
    return temp;
}

bool isFinalcmp(pair<int, int> p1, pair<int, int> p2) {
    int p1_first = p1.first;
    int p2_first = p2.first;
    if(p1_first == p2.first) {
        int p1_second = p1.second;
        int p2_second = p2.second;
        if(p1_second > p2_second) return false;
        else return true;
    } else if(p1_first > p2.first) {
        return true;
    } else if(p1_first < p2.first) {
        return false;
    } else {}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int len = genres.size();
    initialize(len, genres, plays);
    vector<pair<string, int>> maxTimeGenres = case1();
    int gSize = maxTimeGenres.size();
    for(int i = 0; i < gSize; ++i) {
        string str = maxTimeGenres[i].first; // 가장 많이 재생된 노래가 앞에 온다.
        // 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
        vector<pair<int, int>> v;
        for(auto iter = genresTime.lower_bound(str); iter != genresTime.upper_bound(str); ++iter) {
            // 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
            // 최대 2개의 곡까지 모은다.
            // 한곡만 있는 경우 한곡만 수록한다.
            v.emplace_back(make_pair(iter->second.first, iter->second.second));
        }
        
        int vSize = v.size();
        sort(v.begin(), v.end(), isFinalcmp);
        if(vSize >= 2) {
            // 장르에 2곡 이상
            answer.emplace_back(v[0].second);
            answer.emplace_back(v[1].second);
        } else {
            // 장르에 1곡만있을 때
            answer.emplace_back(v[0].second);
        }
    }
    return answer;
}

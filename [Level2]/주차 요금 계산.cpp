#include <string>
#include <vector>
#include <sstream>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
// 시, 분, 차량 번호, 입/출차 
vector<tuple<int, int, int, string>> info;
// 차량 번호, 분
map<int, int> checkCarTime;
// 차량 번호, 입출차 횟수
map<int, int> inOutCnt;

bool cmp(tuple<int, int, int, string> t1, tuple<int, int, int, string> t2) {
    int t1num = get<2>(t1);
    int t2num = get<2>(t2);
    return t1num < t2num; // 오름 차순으로 정렬
}

pair<int, int> setTimeStr(string timestr) {
    pair<int, int> time_;
    string s1 = "";
    string s2 = "";
    // 시
    s1 += timestr[0];
    s1 += timestr[1];
    
    // 분
    s2 += timestr[3];
    s2 += timestr[4];
    time_.first = stoi(s1);
    time_.second = stoi(s2);
    return time_;
}

void setdivideStr(vector<string> s, int size) {
    for(int i = 0; i < size; ++i) {
       stringstream sstr(s[i]);
       string arr[3]; // 분리할 문자열 저장
       sstr >> arr[0] >> arr[1] >> arr[2];
       pair<int, int> timeStr = setTimeStr(arr[0]);
       checkCarTime[stoi(arr[1])] = 0;
       inOutCnt[stoi(arr[1])] += 1; // 입출차 횟수를 기록한다.
       tuple<int, int, int, string> t(timeStr.first, timeStr.second, stoi(arr[1]), arr[2]);
       info.emplace_back(t);
    }
}

void insertOutList() {
    for(auto iter = inOutCnt.begin(); iter != inOutCnt.end(); ++iter) {
        if(iter->second % 2 != 0) {
            /* 
            홀수인 경우-> 입차하고 출차는 안함
            23:59분에 나간것으로 간주
            */
           int hourtime = 23;
           int mintime = 59;
           tuple<int, int, int, string> t(hourtime, mintime, iter->first, "OUT");
           info.emplace_back(t);
        }
    }
}

void calculateTime(int len) {
    int curCarNumber = get<2>(info[0]);

    int inhour = 0;
    int inmin = 0;
    int outhour = 0;
    int outmin = 0;
    
    for(int i = 0; i < len; ++i) {
        string inout = get<3>(info[i]);

        if(get<2>(info[i]) == curCarNumber) {
            if(inout.compare("IN") == 0) {
                inhour = get<0>(info[i]);
                inmin = get<1>(info[i]);
            } else {
                // OUT
                outhour = get<0>(info[i]);
                outmin = get<1>(info[i]);

                // IN, OUT 시간을 계산한다.
                int sumhour = 0;
                int summin = 0;
                if(outmin >= inmin) {
                    sumhour = outhour - inhour;
                    summin = outmin - inmin;
                } else {
                    // inmin > outmin
                    outhour -= 1;
                    outmin += 60;
                    sumhour = outhour - inhour;
                    summin = outmin - inmin;
                }
                checkCarTime[curCarNumber] += ((sumhour * 60) + (summin));
            }
        } else {
            // 새로운 번호 차 등장
            curCarNumber = get<2>(info[i]);

            if(inout.compare("IN") == 0) {
                inhour = get<0>(info[i]);
                inmin = get<1>(info[i]);
            } else {
                // OUT
                outhour = get<0>(info[i]);
                outmin = get<1>(info[i]);

                // IN, OUT 시간을 계산한다.
                int sumhour = 0;
                int summin = 0;
                if(outmin >= inmin) {
                    sumhour = outhour - inhour;
                    summin = outmin - inmin;
                } else {
                    // inmin > outmin
                    outhour -= 1;
                    outmin += 60;
                    sumhour = outhour - inhour;
                    summin = outmin - inmin;
                }
                checkCarTime[curCarNumber] += ((sumhour * 60) + (summin));
            }
        }
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    int gSize = records.size();
    setdivideStr(records, gSize);
    insertOutList();
    stable_sort(info.begin(), info.end(), cmp);

    int len = info.size();
    calculateTime(len);
    // 총 요금 계산
    vector<int> answer;
    for(auto iter = checkCarTime.begin(); iter != checkCarTime.end(); ++iter) { 
       int totalmoney = fees[1]; // 기본 요금
       if(iter->second > fees[0]) {
            iter->second -= fees[0];
            // 단위 시간 당 
            if((iter->second % fees[2]) == 0) {
            } else {
                totalmoney += fees[3];
            }
            int d = iter->second / fees[2];
            totalmoney += (d * fees[3]);
       }
       answer.emplace_back(totalmoney);
    }
    return answer;
}

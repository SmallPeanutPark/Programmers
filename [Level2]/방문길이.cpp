#include <string>
#include <set>
#include <utility>
#include <iostream>
#include <tuple>
using namespace std;

set<tuple<int, int, int, int>> location; // 좌표 값 저장

// 'U', 'R', 'L', "D" (위 오른 왼 아래)

bool isSuccessMove(int nx, int ny) {
    if((ny > 5) || (ny < -5)) return false;
    if((nx > 5) || (nx < -5)) return false;
    return true;
}

int calculateMove(string& s) {
    int len = s.length();
    int distance = 0;
    tuple<int, int, int, int> cur(0, 0, 0, 0); // 현재 x,y -> 다음 x y
    for(int i = 0; i < len; ++i) {
        int curX = get<0>(cur);
        int curY = get<1>(cur);
        int nextX = curX;
        int nextY = curY;
        if(s[i] == 'U') {
            // y좌표 +1
            nextY += 1;
            if(!isSuccessMove(nextX, nextY)) continue;
            auto result = location.insert(make_tuple(curX, curY, nextX, nextY));
            auto reverse_result = location.insert(make_tuple(nextX, nextY, curX, curY));
            if(result.second && reverse_result.second) {
                // success
                distance += 1;
            }
        } else if(s[i] == 'D') {
            // y좌표 +1
            nextY -= 1;
            if(!isSuccessMove(nextX, nextY)) continue;
            auto result = location.insert(make_tuple(curX, curY, nextX, nextY));
            auto reverse_result = location.insert(make_tuple(nextX, nextY, curX, curY));
            if(result.second && reverse_result.second) {
                // success
                distance += 1;
            }
        } else if(s[i] == 'L') {
            // y좌표 +1
            nextX -= 1;
            if(!isSuccessMove(nextX, nextY)) continue;
            auto result = location.insert(make_tuple(curX, curY, nextX, nextY));
            auto reverse_result = location.insert(make_tuple(nextX, nextY, curX, curY));
            if(result.second && reverse_result.second) {
                // success
                distance += 1;
            }
        } else if(s[i] == 'R') {
            // x좌표 +1
            nextX += 1;
            if(!isSuccessMove(nextX, nextY)) continue;
            auto result = location.insert(make_tuple(curX, curY, nextX, nextY));
            auto reverse_result = location.insert(make_tuple(nextX, nextY, curX, curY));
            if(result.second && reverse_result.second) {
                // success
                distance += 1;
            }
        } else {}
        get<0>(cur) = nextX;
        get<1>(cur) = nextY;
    }
    return distance;
}

int solution(string dirs) {
    // 0, 0 시작
    location.insert(make_tuple(0, 0, 0, 0)); // 처음 위치 -> 이동한 위치
    int answer = calculateMove(dirs);
    return answer;
}

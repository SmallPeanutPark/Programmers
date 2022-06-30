#include <string>
#include <list>
#include <vector>
#include <queue>
#include <memory>
#include <algorithm>

using namespace std;


class Store {
public:
    Store(int n, char d) {
        this->value = n;
        this->character = d;
    }
    ~Store() = default;
public:
    int getValue() {
        return this->value;
    }
    int getIndex() {
        return this->character;
    }
public:
    bool operator==(int n) {
        return this->value == n ? true : false;
    }
private:
    int value = 0;
    char character = ' ';
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int index = 0;
    int cnt = 0;
    list<Store> mlist;
    priority_queue<int> pq;


    for (int k = 0; k < priorities.size(); ++k) {
        if (location == k) {
            Store s(priorities[k], '1');
            mlist.push_back(s);
        }
        else {
            Store s(priorities[k], '0');
            mlist.push_back(s);
        }
        pq.push(priorities[k]);
    }

    while (!mlist.empty()) {

        if (mlist.front() == pq.top()) {
            shared_ptr<Store> s = make_shared<Store>(mlist.front());
            if (s->getIndex() == '1') {
                answer += 1;
                break;
            }
            mlist.pop_front();
            pq.pop();
            answer += 1;
        }
        else {
            mlist.push_back(mlist.front());
            mlist.pop_front();
        }
    }

    return answer;
}

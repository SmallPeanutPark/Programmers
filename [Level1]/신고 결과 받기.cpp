#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int id_list_len = id_list.size();
    vector<pair<string, int>> user_check;

    for (int i = 0; i < id_list_len; ++i) {
        user_check.push_back(make_pair(id_list[i], 0));
    }

    vector<int> answer;
    map<pair<string, string>, int> m; // report, 횟수 저장
    map<pair<string, string>, int>::iterator m_iter;

    map<string ,int> usercase_report; // 피의자, 횟수 저장
    map<string, int>::iterator usercase_report_iter;

    vector<string> stop_id; // 정지 아이디 저장 신고횟수가 k보다 크거나 같을 때 저장

    int report_len = report.size();
    for (int i = 0; i < report_len; ++i) {
        auto iter = report[i].find(' ');
        string client = report[i].substr(0, iter);
        string suspect = report[i].substr(++iter);
        m_iter = m.find(make_pair(client, suspect));
        if (m.end() == m_iter) {
            m.insert(make_pair(make_pair(client, suspect), 1));
        }

        usercase_report_iter = usercase_report.find(suspect);
        if ((m.end() == m_iter) && (usercase_report.end() != usercase_report_iter)) {
            usercase_report_iter->second += 1;
        }
        else {
            usercase_report.insert(make_pair(suspect, 1));
        }
    }

    // 정지되는 아이디 구하기
    for (usercase_report_iter = usercase_report.begin(); 
        usercase_report_iter != usercase_report.end(); 
        ++usercase_report_iter) {
        if (usercase_report_iter->second >= k) {
            stop_id.push_back(usercase_report_iter->first);
        }
        else {
            continue;
        }
    }

    // 결과 출력
    int stop_id_len = stop_id.size();
    for (int i = 0; i < id_list_len; ++i) {
        string user_id = user_check[i].first; // 유저 아이디
        for (m_iter = m.begin(); m_iter != m.end(); ++m_iter) {
            if (user_id.compare(m_iter->first.first) == 0) {
                // 유저 아이디와 의뢰인이 같을 때, 신고한 대상이 정지당했는지 확인
                for (int j = 0; j < stop_id_len; ++j) {
                    if (m_iter->first.second.compare(stop_id[j]) == 0) {
                        // 같다면
                        user_check[i].second += 1;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < id_list_len; ++i) {
        answer.push_back(user_check[i].second);
    }

    return answer;
}

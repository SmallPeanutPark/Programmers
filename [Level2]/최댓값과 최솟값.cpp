#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string s)
{
	stringstream st(s);
	vector<int> str_vec;
	string v;
	int num = 0;
	string answer = "";

	while (st >> v)
	{
		num = stoi(v);
		str_vec.push_back(num);
		v.clear();
	}

	sort(str_vec.begin(), str_vec.end());
	answer += to_string(str_vec[0]);
	answer += ' ';

	sort(str_vec.begin(), str_vec.end(), greater<int>());
	answer += to_string(str_vec[0]);


	return answer;
}

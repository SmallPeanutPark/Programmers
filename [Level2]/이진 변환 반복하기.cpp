#include <string>
#include <vector>

using namespace std;

int num0 = 0;
int cnt = 0;

int DeleteZeroNum(string s)
{
	string str = "";
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] - '0' != 0)
		{
			str += s[i];
		}
		else
		{
			num0 += 1;
		}
	}
	int strlen = str.length();
	return strlen;
}


string BinaryChange(int length)
{
	int share = 0;
	int remainder = 0;

	string str = "";
	vector<int> vec;

	while (length != 1)
	{
		share = length / 2;
		remainder = length % 2;
		vec.push_back(remainder);

		length = share;
	}

	vec.push_back(1);
	
	for (int i = vec.size() -1; i >= 0; --i)
	{
		str += vec[i] + '0';
	}

	return str;
}


vector<int> solution(string s)
{
	vector<int> answer;
	
	int strlen = s.length();
	while (true)
	{
		strlen = DeleteZeroNum(s);
		s = BinaryChange(strlen);
		cnt += 1;
		if (s.length() == 1)
		{
			break;
		}
	}
	
	answer.push_back(cnt);
	answer.push_back(num0);
	
	return answer;
}

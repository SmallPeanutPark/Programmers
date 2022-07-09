#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
	string answer = "";
	
	vector<unsigned char> vec;

	for (int i = 0; i < s.length(); ++i)
	{
		vec.push_back(s[i]);

		if (vec[i] == ' ')
		{
			// 0x20, space
			vec[i] = ' '; 
		}
		else if (vec[i] >= 'A' && vec[i] <= 'Z')
		{
			// ASCII 65 ~ 91
			vec[i] = vec[i] + n;
			if (vec[i] > 'Z')
			{
				int position = vec[i] - 'Z';
				vec[i] =('A'-1) + position;
			}
		}
		else
		{
			 // ASCII 97 ~ 123
			vec[i] = vec[i] + n;
			if (vec[i] > 'z')
			{
				int position = vec[i] - 'z';
				vec[i] = ('a'-1) + position;
			}
		}

	}

	for (int i = 0; i < vec.size(); ++i)
	{
		answer += vec[i];
	}
	return answer;
}

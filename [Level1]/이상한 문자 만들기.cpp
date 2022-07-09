#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	string answer = "";
	int index = 0; 

	for (int i = 0; i < s.length(); ++i)
	{

		if ((index % 2 == 0) && ('a' <= s[i] && s[i] <= 'z'))
		{
			s[i] -= 32;
			index++;
		}
		else if ((index % 2 != 0) && ('a' <= s[i] && s[i] <= 'z'))
		{
			index++;
		}
		else if ((index % 2 == 0) && ('A' <= s[i] && s[i] <= 'Z'))
		{
			index++;
		}
		else if ((index % 2 != 0) && ('A' <= s[i] && s[i] <= 'Z'))
		{
			s[i] += 32;
			index++;
		}
		else if (s[i] == ' ')
		{
			index = 0;
		}
	}

	answer = s;

	return answer;
}

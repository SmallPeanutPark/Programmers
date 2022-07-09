#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
	int index = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		if (isalpha(s[i]) && (index == 0))
		{
			++index;
            if(islower(s[i]))
            {
                //s[i] -= 32;
                s[i] = toupper(s[i]);
            }
		}
   		else if (isdigit(s[i]) && (index == 0))
		{
			++index;
		}
		else if (isalpha(s[i]) && (index != 0))
		{
			++index;
			if (isupper(s[i]))
			{
				//s[i] += 32;
                s[i] = tolower(s[i]);
			}
		}
		else if (s[i] == ' ')
		{
			index = 0;
			continue;
		}
		else
		{

		}
	}

	answer = s;

	return answer;
}

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> temp_stack;

	for (int i = 0; i < s.size(); ++i)
	{
		if (i == 0)
		{
			temp_stack.push(s[i]); // init
		}
		else
		{
			if (!temp_stack.empty())
			{
				if (temp_stack.top() == s[i])
				{
					temp_stack.pop();
				}
				else
				{
					temp_stack.push(s[i]);
				}
			}
			else
			{
				temp_stack.push(s[i]);
			}
		}
	}

	if (!temp_stack.empty())
	{
		answer = 0;
	}
	else
	{
		answer = 1;
	}

	return answer;
}

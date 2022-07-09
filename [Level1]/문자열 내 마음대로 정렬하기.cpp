#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index;


bool str_sort(string& str1, string& str2)
{
	if (str1[index] == str2[index])
	{
		if (str1 > str2)
		{
			return false;
		}
		else
		{
			return true;
		}
		
	}
	else if (str1[index] > str2[index])
	{ 
		return false;
	}
	else if (str1[index] < str2[index])
	{
		return true;
	}
	else
	{
		//do nothing
	}

}

vector<string> solution(vector<string> strings, int n)
{
	index = n;

	vector<string> answer;

	sort(strings.begin(), strings.end(), str_sort);

	answer = strings;

	return answer;
}

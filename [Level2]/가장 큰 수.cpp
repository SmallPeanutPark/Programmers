#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool string_compare(int num1, int num2)
{
	string str1 = to_string(num1) + to_string(num2);
	string str2 = to_string(num2) + to_string(num1);

	return str1 > str2;
}


string solution(vector<int> numbers)
{
	string answer = "";

	sort(numbers.begin(), numbers.end(), string_compare);
	if (numbers[0] == 0)
	{
		answer = '0';
	}
	else
	{
		for (int i = 0; i < numbers.size(); ++i)
		{
			answer += to_string(numbers[i]);
		}
	}

	return answer;
}

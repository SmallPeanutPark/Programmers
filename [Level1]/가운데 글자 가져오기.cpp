#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
	int str_length = s.length(); 
	int judgment = str_length % 2; 
	int odd_even = (str_length / 2) - 1;
	

	if (judgment == 0)
	{
		answer.insert(0, 1, s[odd_even]);
		answer.insert(1, 1, s[odd_even + 1]);
	}
	else
	{
		answer.insert(0, 1, s[odd_even + 1]);
	}

	return answer;
}

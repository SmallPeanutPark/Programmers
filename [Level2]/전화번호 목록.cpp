#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool solution(vector<string> phone_book)
{
	bool answer = true;

	sort(phone_book.begin(), phone_book.end());
	
	for (int i = 0; i < phone_book.size(); ++i)
	{
		int str_length = phone_book[i].length();
		for (int j = i + 1; j < phone_book.size(); ++j)
		{
			string str = phone_book[j].substr(0, str_length);
			
			if (phone_book[i] == str)
			{
				return false;
			}
		}
	}

	return answer;
}

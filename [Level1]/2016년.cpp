#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    	string answer = "";
	vector<int> day = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
						// 1,  2,    3,  4,   5,   6,   7,   8,  9,  10, 11, 12
	vector<string> day_str = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
							//  1       2         3         4          5         6          7    
	int day_sum = 0;

	for (int i = 0; i < a; ++i)
	{
		if (i == a - 1)
		{
			day_sum += b - 1;
		}
		else
		{
			day_sum += day[i];
		}

	}
	
	day_sum %= 7;

	answer += day_str[day_sum];

	return answer;
}

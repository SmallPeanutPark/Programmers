#include <string>
#include <cmath>
#include <vector>

#include <iostream>

using namespace std;

int solution(string dartResult)
{
	int answer = 0;

	int number_save = 0;
	int number_cnt = 0;
	int opportunity = 0;
	int star_cnt = 0;
	int pow_result = 0;

	vector<int> total_result;


	for (int i = 0; i < dartResult.size(); ++i)
	{
		int index = (i + 1);

		if (isalpha(dartResult[i]) != 0)
		{
			if (dartResult[i] == 'S')
			{
                pow_result = pow(number_save, 1);
			}
			else if (dartResult[i] == 'D')
			{
			    pow_result = pow(number_save, 2);
			}
			else
			{
				pow_result = pow(number_save, 3);
			}

			++number_cnt;
			number_save = 0;
		}
		else if ((dartResult[i] == '*') || (dartResult[i] == '#'))
		{
			if (dartResult[i] == '*') 
			{
				++star_cnt;
				if ((star_cnt >= 1) && (opportunity > 0))
				{
					if (opportunity > 1)
					{
						total_result[1] = total_result[1] * 2;
					}
					else
					{
						total_result[star_cnt - 1] = total_result[star_cnt - 1] * 2;
					}
				}
				total_result.push_back(pow_result * 2);
				--star_cnt;
				
			}
			else // #
			{
				total_result.push_back(pow_result * -1);
			}
			++number_cnt;
			++opportunity;
		}
		else if(isdigit(dartResult[i]) != 0)
		{
			if ((dartResult[i] == '1') && (dartResult[index] == '0'))
			{
				number_save = (dartResult[i] - '0') * 10;
				++i;
				++number_cnt;
				continue;
			}
			else
			{
				number_save = dartResult[i] - '0';
				++number_cnt;
			}
		}
		
		if ((number_cnt == 2) && ((dartResult[index] != '#') && (dartResult[index] != '*')))
		{
			total_result.push_back(pow_result);
			number_cnt = 0;
			++opportunity;
		}
		else if (number_cnt == 3)
		{
			number_cnt = 0;
		}
	}

	for (int i = 0; i < total_result.size(); ++i)
	{
		answer += total_result[i];
	}


	return answer;
}

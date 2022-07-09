#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	int answer = 0;

	int range = (n / 2) + 1;
	int sum = 0;

	for (int i = 1; i <= range; ++i)
	{
		sum += i;
		for (int j = i + 1; j <= range; ++j)
		{
			sum += j;
			if (sum == n)
			{
				sum = 0;
				answer += 1;
				break;
			}
			else if (sum > n)
			{
				sum = 0;
				break;
			}
			else
			{
				// do nothing
			}
		}
	}

	answer += 1;

	return answer;
}

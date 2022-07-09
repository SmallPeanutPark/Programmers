#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n)
{
	int answer = 0;
	vector<int>  space;
	do
	{
		int num = n % 3;
		space.push_back(num);
		if (n < 3)
		{
			break;
		}
		else
		{
			n /= 3;
			if (n == 1)
			{
				space.push_back(1);
				break;
			}
		}
	} while (true);

	int pow_num = 0;
	for (int i = space.size() - 1; i >= 0; --i)
	{
		answer += space[i] * pow(3, pow_num);
		++pow_num;
	}

	return answer;
}

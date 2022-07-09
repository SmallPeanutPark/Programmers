#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
   vector<int> answer;
	int max_num = 0;
	if (n <= m) // 오른쪽 수가 더 크거나 같은 경우
	{
		for (int i = 1; i <= n; ++i)
		{
			if ((n % i == 0) && (m % i == 0))
			{
				max_num = i; // 나누었을 때 둘다 모두 0이 되는 최대 값이 마지막에 저장
			}
		}
	}
	
	if (n >= m) // 왼쪽 수가 더 크거나 같은 경우
	{
		for (int i = 1; i <= m; ++i)
		{
			if ((n % i == 0) && (m % i == 0))
			{
				max_num = i; // 나누었을 때 둘다 모두 0이 되는 최대 값이 마지막에 저장
			}
		}
	}

	//최대 값으로 나누었을때 몫과 최대값과 곱

	answer.push_back(max_num);
	answer.push_back(max_num*(n / max_num) * (m / max_num));

	return answer;
}

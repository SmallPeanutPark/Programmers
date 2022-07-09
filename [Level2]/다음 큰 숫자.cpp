#include <string>
#include <vector>

using namespace std;

int Binary_Conversion(int n)
{
	vector<int> answer;
	int cnt = 0;
	int share = 0;
	int remainder = 0;

	while (share != 1)
	{
		share = n / 2;
		remainder = n % 2;

		answer.push_back(remainder);
		n = share;
	}
	
	answer.push_back(share);
	
	for (int i = 0; i < answer.size(); ++i)
	{
		if (answer[i] == 1)
		{
			cnt += 1;
		}
	}

	return cnt;
}



int solution(int n)
{
	int answer = 0;
	
	int cnt = Binary_Conversion(n);
	int compare_num = n + 1; // init

	while (true)
	{
		int compare_cnt = Binary_Conversion(compare_num);

		if (compare_cnt == cnt)
		{
			answer = compare_num;
			break;
		}
		compare_num += 1;
	}


	return answer;
}

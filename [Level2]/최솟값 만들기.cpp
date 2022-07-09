#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	vector<int> total;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end()); 

	int length = A.size();
	for (int i = 0; i < length; ++i)
	{
		int min_gop = ((*(A.begin() + i)) * (*(B.begin() + (length - 1 - i))));
		answer += min_gop;
	}

	return answer;
}

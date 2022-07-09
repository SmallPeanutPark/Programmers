#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> citations)
{
	int answer = 0;
	sort(citations.begin(), citations.end());
	int compare_value = 0;

	int borrow_over = 0; 

	vector<int> ans;
	while (compare_value <= citations.size())
	{
		borrow_over = 0;
		for (int i = 0; i < citations.size(); ++i)
		{
			if (compare_value <= citations[i])
			{
				borrow_over += 1;
			}
		}

		if (compare_value <= borrow_over)
		{
			if (citations.size() - borrow_over <= compare_value)
			{
				ans.push_back(compare_value);
			}
		}

		compare_value += 1;
	}

	answer = *max_element(ans.begin(), ans.end());

	return answer;
}

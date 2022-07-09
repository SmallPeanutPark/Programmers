#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
  vector<int> answer;
	vector<int> user1 = { 1, 2, 3, 4, 5 };
	vector<int> user2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> user3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;


	for (int i = 0; i < answers.size(); ++i)
	{
		
		if (answers[i] == user1[i % 5])
		{
			++count1; 
		}

		if (answers[i] == user2[i % 8])
		{
			++count2;
		}

		if (answers[i] == user3[i % 10])
		{
			++count3;
		}
	}
    
	int max_count = count1;

	if (count2 > max_count)
	{
		max_count = count2;
	}

	if (count3 > max_count)
	{
		max_count = count3;
	}


	if (max_count == count1)
	{
		answer.push_back(1);
	}

	if (max_count == count2)
	{
		answer.push_back(2); 
	}

	if (max_count == count3)
	{
		answer.push_back(3);
	}

	return answer;
}

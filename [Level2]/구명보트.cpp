#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
	int answer = 0;

	sort(people.begin(), people.end()); // 오름 차순 정렬

	int index = people.size() - 1; // 비교할 인덱스
	int total_weight = 0;
	for (int i = 0; i < people.size(); ++i)
	{
		if (people[i] == 0)
		{
			continue;
		}
		else
		{
			if ((i != index) && (index >= 0))
			{
				total_weight = people[i] + people[index];

				if (total_weight <= limit)
				{
					// 보트에 탄 인원은 몸무게를 0으로 만듬
					++answer;
					people[i] = 0;
					people[index] = 0;
					--index;
				}
				else
				{
					i = -1;
					--index;
				}
			}
		}
	}

	for (int i = 0; i < people.size(); ++i)
	{
		if (people[i] != 0)
		{
			++answer;
		}
	}

	return answer;
}

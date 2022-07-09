#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;



vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	vector<float> temporary;
	temporary.push_back(-1);


	sort(stages.begin(), stages.end());

	float person_count = 0;
	float all_person = stages.size();

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < stages.size(); ++j)
		{
            int index = j + 1;
			if (i == stages[j])
			{
				++person_count;
			}     
		}
        
		if (person_count != 0)
		{
			temporary.push_back(person_count / all_person);
			all_person -= person_count;
			person_count = 0;
		}
		else
		{
			temporary.push_back(0);
		}
	}

	multimap<float, int, greater<float>> total_value;
	
	for (int i = 1; i < temporary.size(); ++i)
	{
		total_value.insert(pair<float, int>(temporary[i], i));
	}

    multimap<float,int, greater<float>>::iterator miter;
    
    for(miter = total_value.begin(); miter != total_value.end(); ++miter)
    {
        answer.push_back(miter->second); // value 값만 가져오도록
    }
	return answer;
}

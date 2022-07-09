#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> map_participant;

	for (int i = 0; i < participant.size(); i++)
	{
		string participant_name = participant[i];
		auto itr = map_participant.insert(make_pair(participant_name, 1));
		if (itr.second == false)
		{
			map_participant[participant_name] += 1;
		}
	}

	for (int i = 0; i < completion.size(); i++)
	{
		string completion_name = completion[i];

		auto itr = map_participant.find(completion_name);
		if (itr != map_participant.end())
		{
			map_participant[completion_name] -= 1;
		}

	}

	for (auto pair : map_participant)
	{
		if (pair.second > 0)
		{
			answer = pair.first;
		}
	}

    return answer;
}

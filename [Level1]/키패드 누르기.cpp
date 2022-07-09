#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
   	string answer = "";
	vector<vector<int>> keypad = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { '*', 0, '#' } };

	vector<int> left_hand_location = { 3, 0 };  // 좌표
	vector<int> right_hand_location= { 3, 2 };
    
	bool chflag = false;
	int L_first = 0;
	int L_second = 0;
	int R_first = 0;
	int R_second = 0;
	
	for (int k = 0; k < numbers.size(); ++k)
	{
		chflag = false;
		for (int i = 0; i < keypad.size(); ++i)
		{
			if (chflag == true)
			{
				break;
			}
            
			for (int j = 0; j < keypad[0].size(); ++j)
			{
				if ((numbers[k] == keypad[i][j]))
				{
					if ((numbers[k] == 1) || (numbers[k] == 4) || (numbers[k] == 7) || (numbers[k] == '*'))
					{
						answer += 'L';
						left_hand_location.clear();
						left_hand_location.push_back(i);
						left_hand_location.push_back(j);
						chflag = true;
						break;
					}
					else if ((numbers[k] == 3) || (numbers[k] == 6) || (numbers[k] == 9) || (numbers[k] == '#'))
					{
						answer += 'R';
						right_hand_location.clear();
						right_hand_location.push_back(i);
						right_hand_location.push_back(j);
						chflag = true;
						break;
					}
					else // 2, 5, 8, 0
					{

						L_first = abs(left_hand_location.front() - i);
						L_second = abs(left_hand_location.back() - j);

						R_first = abs(right_hand_location.front() - i);
						R_second = abs(right_hand_location.back() - j);

						if ((L_first + L_second) > (R_first + R_second))
						{
							answer += 'R';
							right_hand_location.clear();
							right_hand_location.push_back(i);
							right_hand_location.push_back(j);
							chflag = true;
							break;
						}
						else if ((L_first + L_second) < (R_first + R_second))
						{
							answer += 'L';
							left_hand_location.clear();
							left_hand_location.push_back(i);
							left_hand_location.push_back(j);
							chflag = true;
							break;
						}
						else
						{
							if (hand == "right")
							{
								answer += 'R';
								right_hand_location.clear();
								right_hand_location.push_back(i);
								right_hand_location.push_back(j);
								chflag = true;
								break;
							}
							else
							{
								answer += 'L';
								left_hand_location.clear();
								left_hand_location.push_back(i);
								left_hand_location.push_back(j);
								chflag = true;
								break;
							}
						}
					
					}
				}


			}
		}

	}
	return answer;
}

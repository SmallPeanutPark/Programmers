#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> value;
int N;

void change_value(int arr)
{
	int result = arr % 2;
	value.push_back(result);
	arr /= 2;
	if (arr == 1)
	{
		value.push_back(1);
		if (value.size() < N)
		{
			for (int i = value.size(); i < N; ++i)
			{
				value.push_back(0);
			}
		}
		return;
	}
	else if (arr == 0)
	{
		if (value.size() < N)
		{
			for (int i = value.size(); i < N; ++i)
			{
				value.push_back(0);
			}
		}
		return;
	}
	else
	{
		change_value(arr);
	}
}


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
	N = n;
	vector<string> answer;
	vector<vector<int>> map1;
	vector<vector<int>> map2;
	
	// arr1
	for (int i = 0; i < arr1.size(); ++i)
	{
		change_value(arr1[i]);
		reverse(value.begin(), value.end());
		map1.push_back(value);
		value.clear();
	}
	// arr2
	for (int i = 0; i < arr2.size(); ++i)
	{
		change_value(arr2[i]);
		reverse(value.begin(), value.end());
		map2.push_back(value);
		value.clear();
	}
	
	string str;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < map1.size(); ++j)
		{
			if ((map1[i][j] == 1) && (map2[i][j] == 1))
			{
				str += '#';
			}
			else if ((map1[i][j] == 1) && (map2[i][j] == 0))
			{
				str += '#';
			}
			else if ((map1[i][j] == 0) && (map2[i][j] == 1))
			{
				str += '#';
			}
			else
			{
				str += ' ';
			}
		}
		answer.push_back(str);
		str.clear();
	}
	

	return answer;
}

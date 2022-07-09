#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
	
	long long num = 0;

	string str = to_string(x);

	for (int i = 0; i < str.length(); ++i)
	{
		int val = str[i] - '0';
		num += val;
	}

	if (x % num == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

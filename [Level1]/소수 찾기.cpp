#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
	vector<int> v(n);

	for (int i = 2; i <= n; ++i)
	{
		for (int j = i + i; j <= n; j += i)
		{
            if (v[j - 1] == 1)
			{
				continue;
			}
			v[j -1] = 1;
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		if (v[i -1] != 1)
		{
			++answer;
		}
	}

	return answer;
}

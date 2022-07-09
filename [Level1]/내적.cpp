#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int total_sum = 0;
	
	for (int i = 0; i < a.size(); ++i)
	{
		total_sum += (a[i] * b[i]);
	}

	return total_sum;
}

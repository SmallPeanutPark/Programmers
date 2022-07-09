#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
  long long answer = -1;
	double cmp = sqrt(n);

	if ((cmp - (long long)cmp) == 0)
	{
		answer = pow((cmp + 1), 2); 
	}

	return answer;
}

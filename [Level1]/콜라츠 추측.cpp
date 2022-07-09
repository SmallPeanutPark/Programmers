#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
	long long n = num;

	while (true)
	{
		if (n % 2 == 0)
		{
			n /= 2;
			++answer;
            if (n == 1)
		    {
			    break;
		    }
		}
		else
		{
			n = (n * 3) + 1;
			++answer;
            if (n == 1)
		    {   
			    break;
		    }
		}

		if ((answer >= 500) && (n != 1))
		{
			answer = -1;
			break;
		}
	}
    
    if(num == 1)
    {
        answer = 0;
    }
    
        
	return answer;
}

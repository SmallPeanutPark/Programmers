#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long sum = 0;
    
    if (a > b)
    {
        for (int i = a; i > b; --i)
        {
            sum += i;
        }

        sum += b;
    }
    else
    {
        for (int i = b; i > a; --i)
        {
            sum += i;
        }

        sum += a;
    }
 
    answer = sum;
    return answer;
}

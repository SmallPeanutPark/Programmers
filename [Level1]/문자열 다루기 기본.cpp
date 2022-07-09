#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
        bool answer = true;
    int strlength = s.length();
    bool flag = true;
    
    for (int i = 0; i < strlength; ++i)
    {
        if ((strlength == 4) || (strlength == 6))
        {
            if ((s[i] - '0') > 10)
            {
                flag = false;
            }
        }
        else
        {
            answer = false;
        }
    }

    if (flag == false)
    {
        answer = false;
    }

    return answer;
}

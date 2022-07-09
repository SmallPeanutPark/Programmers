#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int pcnt = 0;
    int ycnt = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if ((s[i] == 'p') || (s[i] == 'P'))
        {
            ++pcnt;
        }
        else if ((s[i] == 'y') || (s[i] == 'Y'))
        {
            ++ycnt;
        }
        else
        {
            //do nothing
        }
    }

    if (pcnt == ycnt)
    {
        answer = true;
    }
    else if (pcnt != ycnt)
    {
        answer = false;
    }
    else if ((pcnt == 0) && (ycnt == 0))
    {
        answer = true;
    }
    else
    {
        //do nothing
    }

    return answer;
}

#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string str = to_string(n);
    string temp = "";
    int str_length = str.length();

    for (int i = 0; i < str_length; ++i)
    {
        temp = str[i];
        answer += stoi(temp);
    }

    return answer;
}

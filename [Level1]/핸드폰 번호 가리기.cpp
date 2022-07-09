#include <string>
#include <vector>

using namespace std;


string solution(string phone_number) {
    string answer = "";
    string temp = "";
    int str_length = phone_number.length() - 4;

    
    temp = phone_number.substr(str_length, 4);
    
    for (int i = 0; i < str_length; ++i)
    {
        answer.append("*");
    }

    answer.append(temp);

    return answer;
}

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int length = arr.size();
    for (int i = 0; i < length; i++)
    {
        int count = i + 1;
        if (count < length)
        {
            if (arr[i] == arr[count])
            {
                //do nothing
            }
            else
            {
                answer.push_back(arr[i]);
            }
        }

        if (count == length)
        {
            if (arr[i] == arr[length - 1])
            {
                answer.push_back(arr[i]);
            }
        }

    }

    return answer;
}

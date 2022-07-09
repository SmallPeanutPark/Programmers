#include <string>
#include <vector>

using namespace std;

string step1_2(string new_id)
{
	string temp = "";
	
	for (int i = 0; i < new_id.length(); ++i)
	{
		if (isupper(new_id[i]))
		{
			
			temp += new_id[i] + 32;
		}
		else
		{
			
			if (((0 <= new_id[i] - '0') && (new_id[i] - '0' <= 9))
				|| (new_id[i] == '-') || (new_id[i] == '_')
				|| (new_id[i] == '.') || (islower(new_id[i])))
			{
				temp += new_id[i];
			}
		}
	}
	return temp;
}

string step3(string new_id)
{
	string temp = "";

	
	for (int i = 0; i < new_id.length(); ++i)
	{
		int j = i + 1;
		if (j < new_id.length())
		{
			if ((new_id[i] == '.') && (new_id[j] == '.'))
			{
				new_id[i] = ' '; 
			}
		}
	}

	
	for (int i = 0; i < new_id.length(); ++i)
	{
		if (new_id[i] == ' ')
		{

		}
		else
		{
			temp += new_id[i];
		}
	}
	
	return temp;                                            
}

string step4(string new_id)
{
	string temp = "";
	
	int last_index = new_id.length() - 1;

	for (int i = 0; i < new_id.length(); ++i)
	{
		if ((i == 0) || (i == last_index))
		{
			if (new_id[i] == '.')
			{
				// pass
			}
			else
			{
				temp += new_id[i];
			}
		}
		else
		{
			temp += new_id[i];
		}

	}

	return temp;
}

string step5(string new_id)
{
	string temp = "";

	if (new_id.length() == 0)
	{
		temp += 'a';
	}
	else 
	{
		temp = new_id;
	}
	
	return temp;
}

string step6(string new_id)
{
	string temp = "";

	if (new_id.length() > 15)
	{
		for (int i = 0; i < 15; ++i)
		{
			temp += new_id[i];
		}
	}
	else
	{
		temp = new_id;
	}

	int temp_length = temp.length() - 1;
	if (temp[temp_length] == '.')
	{
		temp.pop_back();
	}

	return temp;
}

string step7(string new_id)
{
	string temp = "";

	if (new_id.length() < 3)
	{
		char temp_str = new_id[new_id.length() - 1];

		for (int i = 0; i < 3; ++i)
		{
			if (new_id.length() < 3)
			{
				new_id += temp_str;
			}
			else
			{
				break;
			}
		}
	}

	temp = new_id;

	return temp;
}

string solution(string new_id)
{
	string answer = "";

	string temp12 = step1_2(new_id); // 1, 2

	string temp3 = step3(temp12); // 3

	string temp4 = step4(temp3); // 4

	string temp5 = step5(temp4); //5
	
	string temp6 = step6(temp5); // 6

	string temp7 = step7(temp6); // 7

	answer = temp7;

	return answer;
}

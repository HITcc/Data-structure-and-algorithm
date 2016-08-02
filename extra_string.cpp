#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int split(const string& str, vector<int>& ret_, string sep = ",")
{
	if (str.empty())
	{
		return 0;
	}

	string tmp;
	string::size_type pos_begin = str.find_first_not_of(sep);
	string::size_type comma_pos = 0;

	while (pos_begin != string::npos)
	{
		comma_pos = str.find(sep, pos_begin);
		if (comma_pos != string::npos)
		{
			tmp = str.substr(pos_begin, comma_pos - pos_begin);
			pos_begin = comma_pos + sep.length();
		}
		else
		{
			tmp = str.substr(pos_begin);
			pos_begin = comma_pos;
		}

		if (!tmp.empty())
		{
			//string -> int
			stringstream ss;
			int int_tmp;
			ss << tmp;
			ss >> int_tmp;

			ret_.push_back(int_tmp);
			tmp.clear();
		}
	}

	return 0;
}

int output_vector(vector<int> vec)
{
	if(vec.empty())
	{
		cout << "The vector is empty!" << endl;
		return 0;
	}

	vector<int>::iterator iter;
	for(iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}

int sum_of_vector(vector<int> vec)
{
	if (vec.empty())
	{
		cout << "The vector in sum function is empty!" << endl;
		return 0;
	} 
	else
	{
		int sum = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			sum += vec[i];
		}
		return sum;
	}
}

int main()
{
	string str;
	int sum;

	while (cin >> str)
	{
		cin >> sum;

		vector<int> vec;
		split(str,vec,",");

		//output_vector(vec);
		//cout << "Sum : " << sum << endl;

		int accout_sum = sum_of_vector(vec);
		if(sum == accout_sum)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}
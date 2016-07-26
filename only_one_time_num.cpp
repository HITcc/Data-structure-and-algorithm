#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//map遍历
void output_map(unordered_map<int,int> vec_count)
{
	unordered_map<int,int>::iterator iter;
	for(iter = vec_count.begin(); iter != vec_count.end(); iter++)
		cout << "Key : " << iter->first << " Value : " << iter->second << endl;
}

//可以处理其他数字出现两次及两次以上
int only_one_time_num(vector<int> vec)
{
	unordered_map<int,int> vec_count;

	for (int i = 0; i < vec.size(); i++)
	{
		if(vec_count.find(vec[i]) != vec_count.end())
			vec_count[vec[i]] += 1;
		else
			vec_count[vec[i]] = 1;
	}

	output_map(vec_count);

	unordered_map<int,int>::iterator iter;
	for(iter = vec_count.begin(); iter != vec_count.end(); iter++)
		if(iter->second == 1)
			return iter->first;

}


//其他数字只出现两次
int only_only_time_num_other_two(vector<int> vec)
{
	int result = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		result = result ^ vec[i];
	}

	return result;
}

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);

	int result;

	result = only_one_time_num(vec);

	cout << "The only one time num in vector is : " << result << endl;

	result = only_only_time_num_other_two(vec);

	cout << "The only one time num other two in vector is : " << result << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void output_vec(vector<int> vec)
{
	vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void recursive_permutation(vector<int> vec,int k,int m)
{
	if (k > m)
	{
		output_vec(vec);
	} 
	else
	{
		for(int i = k; i <= m; i++)
		{
			swap(&vec[k],&vec[i]);
			recursive_permutation(vec,k+1,m);
			swap(&vec[k],&vec[i]);
		}
	}
}

int main()
{
	vector<int> vec;
	int num  = 3;

	for(int i = 0; i < num; i++)
	{
		vec.push_back(i+1);
	}

	swap(vec[0],vec[vec.size()-1]);

	cout << "The init vector : ";
	output_vec(vec);

	//next_permutation function should combine with sort function in algorithm
	sort(vec.begin(),vec.end());
	cout << "Use next_permutation function in algorithm : " << endl;
	do 
	{
		output_vec(vec);
	} while (next_permutation(vec.begin(),vec.end()));

	cout << "Recursive permutation : " << endl;
	recursive_permutation(vec,0,vec.size()-1);

	return 0;
}
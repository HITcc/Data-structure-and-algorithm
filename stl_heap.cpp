#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

bool cmp(int a,int b)
{
	return a > b;
}

void output_vector(vector<int> vec)
{
	vector<int>::iterator iter;
	for(iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void default_stl_heap(vector<int> vec)
{
	//algorithm provides make_heap,push_heap,pop_heap,sort_heap function
	make_heap(vec.begin(),vec.end());
	cout << "Default max heap vector : ";
	output_vector(vec);

	//大顶推得到从小到大的序列
	sort_heap(vec.begin(),vec.end());
	cout << "Default sort heap vector :";
	output_vector(vec);
}

void define_stl_heap(vector<int> vec)
{
	make_heap(vec.begin(),vec.end(),cmp);
	cout << "Define min heap vector : ";
	output_vector(vec);

	sort_heap(vec.begin(),vec.end(),cmp);
	cout << "Define sort heap vector :";
	output_vector(vec);
}

int main()
{
	srand(time(NULL));
	vector<int> vec;
	int num = 10;
	int i;

	for(i = 0; i < num; i++)
		vec.push_back(rand()%50+1);

	cout << "Init vector : ";
	output_vector(vec);

	default_stl_heap(vec);

	define_stl_heap(vec);

	return 0;
}

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int num = 50;
const int k = 5;

void output_vec(vector<int> vec,int k)
{
	for(int i = 0; i < k; i++)
		cout << vec[i] << " ";
	cout << endl;
}

void swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(vector<int> vec,int k)
{
	int index = 0;
	for (int i = 0; i < vec.size()-1; i++)
	{
		if (index < k)
		{
			for(int j = i+1; j < vec.size(); j++)
			{
				if (vec[i] > vec[j])
				{
					swap(&vec[i],&vec[j]);
				}
			}
		}
		else
			break;
	}

	output_vec(vec,k);
}

//最大堆
void adjust_heap(vector<int> &vec,int i,int n)
{
	int tmp;
	int child;  

	for (tmp = vec[i]; 2*i+1 < n; i = child)
	{
		child = 2*i+1;

		if(child != n-1 && vec[child] < vec[child+1])   //找到更大的子节点
			child++;

		if (tmp < vec[child])      //满足条件则交换
			vec[i] = vec[child];
		else
			break;
	}

	vec[i] = tmp;
}

void push_heap(vector<int> &vec,int num)
{
	vec.push_back(num);
	int i;

	for (i = vec.size()-1; i>0 && num > vec[(i-1)/2]; i = (i-1)/2)
		vec[i] = vec[(i-1)/2];

	vec[i] = num;
}

void pop_heap(vector<int> &vec)  //int &max
{
	if(vec.empty())
		return;
	
	//int max = vec[0];
	vec[0] = vec[vec.size()-1];
	vec.resize(vec.size()-1);

	adjust_heap(vec,0,vec.size());

}

void make_heap(vector<int>& vec)
{
	for(int i = vec.size()/2; i >= 0;i--)
		adjust_heap(vec,i,vec.size());
}

void sort_heap(vector<int>& vec)
{
	for(int i = vec.size()-1; i>0 ; i--)
	{
		swap(&vec[0],&vec[i]);
		adjust_heap(vec,0,i);
	}
}

void test_heap(vector<int>& vec)
{
	cout << "make heap : " << endl;
	make_heap(vec);
	output_vec(vec,vec.size());

	cout << "push heap : " << endl;
	push_heap(vec,1001);
	output_vec(vec,vec.size());

	cout << "pop heap : " << endl;
	pop_heap(vec);
	output_vec(vec,vec.size());

	cout << "heap sort : " << endl;
	sort_heap(vec);
	output_vec(vec,vec.size());
}

int main()
{
	srand(time(NULL));
	vector<int> vec;
	int i;

	for(i = 0; i < num; i++)
	{
		vec.push_back(rand()%1000+1);
	}

	cout << "Init vector : " << endl;
	output_vec(vec,vec.size());

	cout << "Sorted vector : " << endl;
	bubble_sort(vec,vec.size());

	cout << "Top k vector with bubble sort : " << endl;
	bubble_sort(vec,k);

	//测试heap的各个基本操作
	//test_heap(vec);

	vector<int> need_sort_vec;
	for (i = 0; i < vec.size(); i++)
	{
		if(i < k-1)
		{
			cout << i << endl;
			need_sort_vec.push_back(vec[i]);
		}
		else if(i == k-1)
		{
			need_sort_vec.push_back(vec[i]);
			make_heap(need_sort_vec);
		}
		else
		{
			push_heap(need_sort_vec,vec[i]);
			pop_heap(need_sort_vec);
		}
	}
	sort_heap(need_sort_vec);
	output_vec(need_sort_vec,need_sort_vec.size());



	return 0;
}
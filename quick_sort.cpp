#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int num = 50;

void output_vec(vector<int> vec)
{
	vector<int>::iterator iter;
	for(iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

int random_index(int low,int high)
{
	srand(time(NULL));
	return low + rand()%(high - low + 1);
}

//返回基准数一趟快排之后的位置
int partition(vector<int> &vec, int low, int high)
{
	int i = low;
	int j = high;
	
	int index = i;
	int x = vec[index]; //确定基准数

	while ( i < j)
	{
		//从后向前找，找到一个小于基准数的进行交换
		while (i < j && vec[j] >= x)
			j--;
		if (i < j)
		{
			vec[i] = vec[j];
			i++;
		}

		//从前向后找，找到一个大于基准数的进行交换
		while(i < j && vec[i] < x)
			i++;
		if(i < j)
		{
			vec[j] = vec[i];
			j--;
		}
	}

	vec[i] = x;

	return i;
}

void quick_sort_core(vector<int> &vec,int low,int high)
{
	if (low < high)
	{
		int index = partition(vec,low,high);
		quick_sort_core(vec,low,index-1);
		quick_sort_core(vec,index+1,high);
	}
}

void quick_sort(vector<int> vec)
{
	if (vec.empty())
		return;
	else
		quick_sort_core(vec,0,vec.size()-1);
	output_vec(vec);
}

int main()
{
	vector<int> vec;

	//随机生成num个1-1000数字
	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		vec.push_back(rand()%1000+1);
	}

	clock_t start = clock();

	quick_sort(vec);

	clock_t end = clock();

	cout << "Quick sort costs " << end-start << "s" << endl;

	return 0;
}
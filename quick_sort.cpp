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

//���ػ�׼��һ�˿���֮���λ��
int partition(vector<int> &vec, int low, int high)
{
	int i = low;
	int j = high;
	
	int index = i;
	int x = vec[index]; //ȷ����׼��

	while ( i < j)
	{
		//�Ӻ���ǰ�ң��ҵ�һ��С�ڻ�׼���Ľ��н���
		while (i < j && vec[j] >= x)
			j--;
		if (i < j)
		{
			vec[i] = vec[j];
			i++;
		}

		//��ǰ����ң��ҵ�һ�����ڻ�׼���Ľ��н���
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

	//�������num��1-1000����
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
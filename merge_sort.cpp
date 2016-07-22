#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int num = 5;
int inverse_pairs_count = 0;

void output_vec(vector<int> vec)
{
	vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

//���ж�����������vec[first...mid]��vec[mid...last]�ϲ��� 
void merge_array(vector<int> &vec,int first,int mid,int last,vector<int> &tmp)
{
	int i = first, j = mid+1;
	int k = 0;

	while (i <= mid && j <= last)
	{
		if(vec[i] < vec[j])
			tmp[k++] = vec[i++];
		else
		{
			tmp[k++] = vec[j++];
			//vec[j]��ǰ��ÿһ������������������� 
			inverse_pairs_count += mid - i + 1;
		}
	}

	while (i <= mid)
		tmp[k++] = vec[i++];

	while(j <= last)
		tmp[k++] = vec[j++];

	//���ź����tmp��ֵ��vec
	for (i = 0;i < k; i++)
		vec[first+i] = tmp[i];
}

void merge_sort_core(vector<int>& vec,int first,int last,vector<int>& tmp)
{
	if (first < last)
	{
		int mid = first + (last - first)/2;
		merge_sort_core(vec,first,mid,tmp);   //����ź���
		merge_sort_core(vec,mid+1,last,tmp);  //�ұ��ź���
		merge_array(vec,first,mid,last,tmp);  //�ٽ�����������������
	}
}

void merge_sort(vector<int>& vec)
{
	if(vec.empty())
		return;
	else
	{
		vector<int> tmp(vec.size());
		merge_sort_core(vec,0,vec.size()-1,tmp);
	}
}

int main()
{
	int i;
	vector<int> vec;
	srand(time(NULL));

	for (i = 0; i < num; i++)
		vec.push_back(rand()%1000+1);

	cout << "Init vec : " << endl;
	output_vec(vec);

	merge_sort(vec);

	cout << "Sorted vec : " << endl;
	output_vec(vec);

	cout << "Inverse pairs count : " << inverse_pairs_count << endl;

	return 0;
}
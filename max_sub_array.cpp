#include <iostream>
#include <vector>
#include <limits>

using namespace std;

//ʱ�临�Ӷȣ�O(n)
int max_sub_array(int a[],int low, int high)
{
	int sum = numeric_limits<int>::min(); //��������С
	int cur_sum = 0;

	for(int i = low; i <= high; i++)
	{
		if (cur_sum > 0)
		{
			cur_sum += a[i];
		}
		else
		{
			cur_sum = a[i];
		}

		if (cur_sum > sum)
			sum = cur_sum;
	}

	return sum;
}

//ʱ�临�Ӷȣ�O��nlogn��
int divide_max_sub_array(int a[],int low,int high)
{
	int sum;

	if (low == high)  //������ֹ����
	{
		sum = a[low];
	}
	else
	{
		int mid = low + (high - low)/2;
		int left_sum = divide_max_sub_array(a,low,mid);
		int right_sum = divide_max_sub_array(a,mid+1,high);

		//mid����
		int cross_left_sum = numeric_limits<int>::min();
		int tmp_left_sum = 0;
		for(int i = mid; i >= low; i--)
		{
			tmp_left_sum += a[i];
			if (tmp_left_sum > cross_left_sum)
				cross_left_sum = tmp_left_sum;
		}

		//mid����
		int cross_right_sum = numeric_limits<int>::min();
		int tmp_right_sum = 0;
		for(int j = mid+1; j <= high; j++)
		{
			tmp_right_sum += a[j];
			if (tmp_right_sum > cross_right_sum)
				cross_right_sum = tmp_right_sum;
		}

		int cross_sum = cross_left_sum + cross_right_sum;

		//��left_sum��right_sum��cross_sum��ѡȡ����
		if (left_sum >= cross_sum && left_sum >= right_sum)
			sum = left_sum;
		else if(right_sum >= left_sum && right_sum >= cross_sum)
			sum = right_sum;
		else
			sum = cross_sum;
	}

	return sum;
}

int main()
{
	/*
	�����������
	��1��-1,-2,-3
	��2��2��-1,3
	��3��-1��-2,3
	*/
	int a[] = {-1,-2,3};

	int max_sum;

	max_sum = max_sub_array(a,0,sizeof(a)/sizeof(a[0])-1);
	cout << "max sub sum of array is : " << max_sum << endl;

	max_sum = divide_max_sub_array(a,0,sizeof(a)/sizeof(a[0])-1);
	cout << "max sub sum of array by dividing is : " << max_sum << endl;

	return 0;
}
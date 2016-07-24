#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int k = 5000;
const int a_len = 50;
const int b_len = 10000;

//划分的思想，时间复杂度为O(log(a_len+b_len))
int k_of_two_sorted_array(int a[],int a_len,int b[],int b_len,int k)
{
	//确保a的长度小于等于b的长度
	if(a_len > b_len)
		return k_of_two_sorted_array(b,b_len,a,a_len,k);

	//终止条件
	if(a_len == 0)
		return b[k-1];
	if(b_len == 0)
		return a[k-1];
	if(k == 1)
		return a[0] < b[0] ? a[0] : b[0];


	
	int a_i = min(k/2,a_len);
	int b_i = k-a_i;

	//*(a+a_i) == a[a_i]
	if(*(a+a_i) > *(b+b_i))
		k_of_two_sorted_array(a,a_len,b+b_i,b_len-b_i,k-b_i);
	else if(*(a+a_i) < *(b+b_i))
		k_of_two_sorted_array(a+a_i,a_len-a_i,b,b_len,k-a_i);
	else
		return *(a+a_i);

}

//暴力比较，时间复杂度为O(a_len+b_len)
int brute_way(int a[],int a_len,int b[],int b_len,int k)
{
	//终止条件
	if(a_len == 0)
		return b[k-1];
	if(b_len == 0)
		return a[k-1];
	if(k == 1)
		return a[0] < b[0] ? a[0] : b[0];

	if(k > 1)
	{
		if (a[0] < b[0])
			brute_way(a+1,a_len-1,b,b_len,k-1);
		else
			brute_way(a,a_len,b+1,b_len-1,k-1);
	}
}

int main()
{
	int i;
	int *a = new int[a_len];
	for (i = 0; i < a_len; i++)
		a[i] = i+1;

	int *b = new int[b_len];
	for (i = 0; i < b_len; i++)
		b[i] = i+1;

	if(k > (a_len + b_len) || k < 1)
	{
		cout << "The k is invalid!" << endl;
		return 0;
	}

	int val;

	clock_t start = clock();

	val = brute_way(a,a_len,b,b_len,k);
	cout << "The " << k << " of two sorted array in brute way is : " << val << endl;

	clock_t brute_way_end  = clock();


	val = k_of_two_sorted_array(a,a_len,b,b_len,k);
	cout << "The " << k << " of two sorted array in divide way is : " << val << endl;

	clock_t divide_way_end  = clock();

	cout << "The brute way costs : " << brute_way_end - start << " s" << endl;
	cout << "The divide way costs : " << divide_way_end - brute_way_end << " s" << endl;


	return 0;
}
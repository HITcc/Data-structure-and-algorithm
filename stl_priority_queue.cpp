#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

struct Node{
	int index;
	int value;
	Node(int idx,int val):index(idx),value(val){};
};

struct cmp
{
	bool operator()(Node a, Node b)
	{
		return a.value > b.value;  //最小值优先
	}
};

int main()
{
	//priority_queue<int>que;//采用默认优先级构造队列  大值优先
	//priority_queue<int,vector<int>,greater<int> >que3;//注意“>>”会被认为错误，
	//priority_queue<int,vector<int>,less<int> >que4;////最大值优先

	priority_queue<Node,vector<Node>,cmp> q;
	int num = 10;
	int i;

	srand(time(NULL));
	for(i = 0; i < num; i++)
		q.push(Node(i+1,rand()%50+1));


	while (!q.empty())
	{
		cout << "Index : " << q.top().index << " " << "Value : " << q.top().value << endl;
		q.pop();
	}

	return 0;
}
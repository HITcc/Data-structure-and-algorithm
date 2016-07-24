#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int val;
	Node* next;
	Node(int value,Node* n = NULL):val(value),next(n){};
};

void output_list(Node* node)
{
	while (node)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}

Node* merge_two_sorted_lists(Node* node_1,Node* node_2)
{
	if(node_1 == NULL)
		return node_2;

	if(node_2 == NULL)
		return node_1;

	Node* pHead = NULL;

	if (node_1->val <= node_2->val)
	{
		pHead = new Node(node_1->val);
		if(node_1 != NULL)
			node_1 = node_1->next;
	} 
	else
	{
		pHead = new Node(node_2->val);
		if(node_2 != NULL)
			node_2 = node_2->next;
	}

	pHead->next = merge_two_sorted_lists(node_1,node_2);

	return pHead;
}

Node* merge_K_sorted_lists(vector<Node*> &lists)
{
	if(lists.empty())
		return NULL;

	while(lists.size() > 1)
	{
		lists.push_back(merge_two_sorted_lists(lists[0], lists[1]));
		lists.erase(lists.begin());
		lists.erase(lists.begin());
	}

	return lists.front();
}

int main()
{
	Node* node_1_1 = new Node(7);
	Node* node_1_2 = new Node(4,node_1_1);
	Node* node_1 = new Node(1,node_1_2);
	cout << "List 1 : " ;
	output_list(node_1);

	Node* node_2_1 = new Node(8);
	Node* node_2_2 = new Node(5,node_2_1);
	Node* node_2 = new Node(2,node_2_2);
	cout << "List 2 : ";
	output_list(node_2);

	Node* node_3_1 = new Node(9);
	Node* node_3_2 = new Node(6,node_3_1);
	Node* node_3 = new Node(3,node_3_2);
	cout << "List 3 : ";
	output_list(node_3);

	Node* pHead = merge_two_sorted_lists(node_1,node_2);
	cout << "Merge List 1 and 2 : ";
	output_list(pHead);

	vector<Node*> lists(3);   //需要先定义size
	lists[0] = node_1;
	lists[1] = node_2;
	lists[2] = node_3;

	Node* pKHead = merge_K_sorted_lists(lists);
	cout << "Merge K Lists : ";
	output_list(pKHead);

	return 0;
}
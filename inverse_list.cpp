#include <iostream>

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

Node* inverse_list(Node* node)
{
	Node* pHead = NULL;
	Node* pPre = NULL;
	Node* pNode = node;

	while (pNode)
	{
		Node* pNext = pNode->next;

		if (pNext == NULL)
			pHead = pNode;

		pNode->next = pPre;   //pNode->next is not same as pNext
		pPre = pNode;
		pNode = pNext;
	}

	return pHead;
}

int main()
{
	Node* node_9 = new Node(9);
	Node* node_8 = new Node(8,node_9);
	Node* node_7 = new Node(7,node_8);
	Node* node_6 = new Node(6,node_7);
	Node* node_5 = new Node(5,node_6);
	Node* node_4 = new Node(4,node_5);
	Node* node_3 = new Node(3,node_4);
	Node* node_2 = new Node(2,node_3);
	Node* node = new Node(1,node_2);

	cout << "The init list : ";
	output_list(node);

	Node* inverse_head = inverse_list(node);
	cout << "Inversed list : ";
	output_list(inverse_head);

	return 0;
}
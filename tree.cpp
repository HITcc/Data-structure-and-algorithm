#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	bool isFirst;
	Node(int value,Node* l = NULL,Node* r = NULL,bool isF = false):val(value),left(l),right(r),isFirst(isF){};
};

Node* InitTree()
{
	Node* leaf_node_1 = new Node(1);
	Node* leaf_node_2 = new Node(2);
	Node* leaf_node_3 = new Node(3);

	Node* node_1 = new Node(1,leaf_node_1,NULL);
	Node* node_2 = new Node(5,leaf_node_2,leaf_node_3);

	Node* root = new Node(6,node_1,node_2);

	return root;
}

void pre_order(Node* root)
{
	if(root != NULL)
	{
		cout << root->val << " ";
		pre_order(root->left);
		pre_order(root->right);
	}
}

void inrecur_pre_order(Node* root)
{
	stack<Node*> s;
	Node* p = root;

	while (!s.empty() || p != NULL)
	{
		while(p != NULL)
		{
			cout << p->val << " ";
			s.push(p);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			p = p->right;
			s.pop();
		}
	}
}

void in_order(Node* root)
{
	if (root != NULL)
	{
		in_order(root->left);
		cout << root->val << " ";
		in_order(root->right);
	}
}

void inrecur_in_order(Node* root)
{
	stack<Node*> s;
	Node* p = root;

	while (!s.empty() || p != NULL)
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			cout << p->val << " ";
			s.pop();
			p = p->right;
		}
	}
}

void post_order(Node* root)
{
	if (root != NULL)
	{
		post_order(root->left);
		post_order(root->right);
		cout << root->val << " ";
	}
}

void inrecur_post_order(Node* root)
{
	stack<Node*> s;
	Node* p = root;

	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			p->isFirst = true;
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();

			if (p->isFirst == true)    //第一次出现在栈顶
			{
			    s.push(p);
				p->isFirst = false;
				p = p->right;
			}
			else       //第二次出现在栈顶
			{
				cout << p->val << " ";
				p = NULL;   //很重要
			}
		}
	}
}

void hierarchy_order(Node* root)
{
    queue<Node*> q;
    Node* p;
    q.push(root);

    while(!q.empty())
    {
        p = q.front();
        cout << p->val << " ";
        q.pop();
        if(p->left != NULL)
            q.push(p->left);
        if(p->right != NULL)
            q.push(p->right);

    }
}

void split_hierarchy_order(Node* root)
{
    queue<Node*> q;
    Node* p;
    q.push(root);
    int cur_hierarchry_count = 1;
    int next_hierarchy_count = 0;

    while(!q.empty())
    {
        if(cur_hierarchry_count > 0)
        {
            p = q.front();
            q.pop();
            if(p != NULL)
                cout << p->val << " ";
            else
                cout << "#" << " ";

            cur_hierarchry_count--;

            if(p != NULL  && (p->left != NULL || p->right != NULL))  //这里运行了C++的判断机制：一旦p != NULL不成立，由于后面的 && 操作符就不继续判断了，从而p->left不会报错
            {
                q.push(p->left);
                next_hierarchy_count++;

                q.push(p->right);
                next_hierarchy_count++;
            }
        }
        else
        {
            cout << endl;
            cur_hierarchry_count = next_hierarchy_count;
            next_hierarchy_count = 0;
        }
    }
}

int main()
{
	Node* root = InitTree();

    cout << "hierarchy_order : ";
	hierarchy_order(root);
	cout << endl;

	cout << "split_hierarchy_order : " << endl;
	split_hierarchy_order(root);
	cout << endl;


	cout << "pre_order : ";
	pre_order(root);
	cout << endl;

	cout << "inrecur_pre_order : ";
	inrecur_pre_order(root);
	cout << endl;

	cout << "in_order : ";
	in_order(root);
	cout << endl;

	cout << "inrecur_in_order : ";
	inrecur_in_order(root);
	cout << endl;

	cout << "post_order : ";
	post_order(root);
	cout << endl;

	cout << "inrecur_post_order : ";
	inrecur_post_order(root);
	cout << endl;

	return 0;
}

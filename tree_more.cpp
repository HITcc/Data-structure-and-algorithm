#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int value,Node* l = NULL,Node* r = NULL):val(value),left(l),right(r){};
};

void output_vector(vector<int> vec)
{
    vector<int>::iterator iter;
    for(iter = vec.begin(); iter != vec.end() ; iter++)
        cout << *iter << " ";
    cout << endl;
}

void hierarchy_order(Node* root)
{
    queue<Node*> q;
    q.push(root);
    Node* p;
    int cur_level_count = 1;
    int next_level_count = 0;

    while(!q.empty())
    {
        if(cur_level_count > 0)
        {
            p = q.front();
            q.pop();
            if(p != NULL)
                cout << p->val << " ";
            else
                cout << "#" << " ";
            cur_level_count--;

            if((p != NULL) && (p->left != NULL || p->right != NULL))
            {
                q.push(p->left);
                next_level_count++;

                q.push(p->right);
                next_level_count++;
            }
        }
        else
        {
            cout << endl;
            cur_level_count = next_level_count;
            next_level_count = 0;
        }

    }
}

void find_path(Node* root,vector<int> &vec,int &sum,int &cur_sum)
{
    vec.push_back(root->val);
    cur_sum += root->val;

    if(root->left == NULL && root->right == NULL && sum == cur_sum)
    {
        output_vector(vec);
    }

    if(root->left != NULL)
        find_path(root->left,vec,sum,cur_sum);

    if(root->right != NULL)
        find_path(root->right,vec,sum,cur_sum);

    vec.pop_back();
    cur_sum -= root->val;
}

Node* get_tree(vector<int> vec)
{
    int vec_size = vec.size();

    if(vec_size == 0)
        return NULL;

    Node* l;
    Node* r;
    Node* root;
    Node* node;
    bool has_left = false;
    bool has_right = false;

    queue<Node*> q;


    for(int i = 0; i < vec_size; i++)
    {
        //左子树
        if(2*i+1 < vec_size)
            l = new Node(vec[2*i+1]);
        else
            l = NULL;

        //右子树
        if(2*i+2 < vec_size)
            r = new Node(vec[2*i+2]);
        else
            r = NULL;

        node = new Node(vec[i],l,r);

        if(i == 0)
        {
            root = node;
        }
        else if(i%2 == 1)
        {
            Node* tmp = q.front();
            tmp->left = node;
            has_left = true;
        }
        else
        {
            Node* tmp = q.front();
            tmp->right = node;
            has_right = true;
        }

        //判断左右子树是否都建立联系
        if(has_left && has_right)
        {
            has_left = false;
            has_right = false;
            q.pop();
        }

        q.push(node);

    }

    return root;
}

int main()
{
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    Node* root = get_tree(vec);
    cout << "Hierarchy order : " << endl;
    hierarchy_order(root);
    cout << endl;


    vector<int> sum_vec;
    int sum = 9;
    int cur_sum = 0;

    cout << "Find path of sum " << sum << " : " << endl;
    find_path(root,sum_vec,sum,cur_sum);


    return 0;
}

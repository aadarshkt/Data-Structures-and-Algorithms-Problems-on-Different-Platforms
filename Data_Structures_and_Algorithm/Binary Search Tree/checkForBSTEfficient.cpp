#include <bits/stdc++.h>
using namespace std;

//Do inorder traversal if it is sorted then the tree is BST
struct Node
{
    int data;
    Node *left, *right;

public:
    Node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};

//Time complexity --> O(n)
void inorderPush(Node *root, vector<int> &ans)
{
    if(root == NULL) return;

    inorderPush(root->left, ans);
    ans.push_back(root->data);
    inorderPush(root->right, ans);
}

//space optimised //First Efficient
bool inorderCheck(Node *root, Node *prev)
{
    if(root == NULL) return true;

    if(!inorderCheck(root->left, prev)) return false;

    if(prev != NULL && root->data < prev->data) return false;
    prev = root;

    if(!inorderCheck(root->right, prev)) return false;

    return true;
}

//Second Efficient.
bool isBSTUtil(struct Node* root, int min, int max)
{
    if(root == NULL) return true;

    if(root->data < max && root->data > min)
    {
        return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
    }

    return false;
}

bool isBST(Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

//Second Efficient with NULL
bool isBSTUtil2(Node *root, Node *min, Node *max)
{
    if(root == NULL) return true;

    if(max != NULL && root->data > max->data)
        return false;
    
    if(min != NULL && root->data < min->data)
        return false;
    
    return isBSTUtil2(root->left, min, root) && isBSTUtil2(root->right, root, max);
}

bool isBST2(Node *root)
{
    return isBSTUtil2(root, NULL, NULL);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    vector<int> v;

    inorderPush(root, v);

    bool flag = true;

    //First solution
    // for(int i=0; i<v.size(); i++)
    // {
    //     if(v[i] > v[i+1])
    //     {
    //         flag = false;
    //         break;
    //     }
    // }

    // flag = isBST(root);

    // flag = isBST2(root);

    flag = inorderCheck(root, NULL);

    if(flag) cout << "Yes BST";
    else cout << "NOT bst";

    return 0;
}
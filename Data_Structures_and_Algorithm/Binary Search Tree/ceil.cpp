#include <bits/stdc++.h>
using namespace std;

//Nearest greater value.
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

Node *insert(Node *root, int key)
{
    if(root == NULL)
        return new Node(key);

    if(key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

Node *ceilBST(Node *root, int x)
{
    Node *res = NULL;
    while(root != NULL)
    {
        int rootValue = root->data;
        if(rootValue == x) return root;
        else if(rootValue < x)
        {
            root = root->right;
        }
        else
        {
            res = root;
            root = root->left;
        }
    }

    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 12);
    root = insert(root, 30);

    cout << ceilBST(root, 14)->data;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

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

Node* insert(Node* root, int key)
{
    if(root == NULL) 
    {
        return new Node(key);
    }

    int rootValue = root->data;

    if(key > rootValue) root->right = insert(root->right, key);
    else if(key < rootValue) root->left = insert(root->left, key);
    
    return root;
}

void print(Node *root)
{
    if(root == NULL) return;

    cout << root->data << " ";

    print(root->left);
    print(root->right);
}

Node *insertIterative(Node *root, int key)
{
    Node *parent, *curr = root, *temp = root;

    int value;

    while(curr != NULL)
    {
        parent = curr;

        value = curr->data;

        if(key > value) curr = curr->right;
        else if(key < value) curr = curr->left;
        else if(key == value) 
        {
            break;
        }

    }

    value = parent->data;

    Node *leaf = new Node(key);

    if(key > value) parent->right = leaf;
    else if(key < value) parent->left = leaf;

    return temp;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    Node *root = new Node(15);
    root->right = new Node(20);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right->right = new Node(80);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);

    insert(root, 6);

    print(root);

    insertIterative(root, 90);

    cout << endl;

    print(root);

    return 0;
}
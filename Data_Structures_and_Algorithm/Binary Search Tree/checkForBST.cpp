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

// BST insert; //Do not use for check BST function :)
Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);

    int rootValue = root->data;

    if (key < rootValue)
    {
        root->left = insert(root->left, key);
    }
    else if (key > rootValue)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

int mini(Node *root)
{
    if (root == NULL)
        return INT_MAX;

    int rootValue = root->data;
    return min({rootValue, mini(root->left), mini(root->right)});
}

int maxi(Node *root)
{
    if (root == NULL)
        return INT_MIN;

    int rootValue = root->data;

    return max({rootValue, maxi(root->left), maxi(root->right)});
}

//Time complexity --> O(n^2);
bool checkForBST(Node *root)
{
    if(root == NULL) return true;

    int rootValue = root->data;
    return maxi(root->left) < rootValue && mini(root->right) > rootValue && checkForBST(root->left) && checkForBST(root->right);
}

void print(Node *root)
{
    if (root == NULL)
        return;

    print(root->left);
    cout << root->data << " ";
    print(root->right);
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

    cout << checkForBST(root);

    return 0;
}
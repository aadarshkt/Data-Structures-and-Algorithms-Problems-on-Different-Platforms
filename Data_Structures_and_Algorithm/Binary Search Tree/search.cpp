#include <bits/stdc++.h>
using namespace std;

// Time complexity --> O(h) //If you closely see, you are travesing only the height of tree. h = logn n is no of nodes.
// Space complexity --> O(h)

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

bool search(Node *root, int key)
{
    if (root == NULL)
        return false;

    int rootValue = root->data;

    if (key == rootValue)
        return true;
    else if (key > rootValue)
        return search(root->right, key);

    return search(root->left, key);
}

//Less space complexity

bool searchIteravtive(Node *root, int key)
{
    int rootValue;

    while (root != NULL)
    {
        rootValue = root->data;

        if(key > rootValue) root = root->right;
        else if(key < rootValue) root = root->left;
        else if(key == rootValue) return true;
    }

    return false;
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

    cout << search(root, 80) << endl;
    cout << searchIteravtive(root, 16);

    return 0;
}
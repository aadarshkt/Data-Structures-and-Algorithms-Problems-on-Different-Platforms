#include <bits/stdc++.h>
using namespace std;

// find closest smaller value.
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

struct Node *insert(struct Node *root, int key)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
        return new Node(key);

    /* Otherwise, recur down the tree */
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    /* return the (unchanged) root pointer */
    return root;
}

void print(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    print(root->left);
    print(root->right);
}

Node *floorBST(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        int rootValue = root->data;
        if (rootValue < x)
        {
            res = root;
            root = root->right;
        }
        else if (rootValue > x)
        {
            root = root->left;
        }
        else if (rootValue == x)
            return root;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    Node *ans = floorBST(root, 71);

    cout << ans->data;

    return 0;
}
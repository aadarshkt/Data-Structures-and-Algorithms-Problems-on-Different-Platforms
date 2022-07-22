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

//Closest greater. Greater is on right. if we do left of that right and keep moving left we will get the closest greater value(all values in right subtree are greater than the root.) 
// This function takes the right node and finds the lowest node left to it. Root node is replaced with that node.
Node *minValueNode(Node *root)
{
    Node *curr = root;

    while (curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    int rootValue = root->data;

    //good one
    if (key < rootValue)
        root->left = deleteNode(root->left, key);
    else if (key > rootValue)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;

        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

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
    root->right->right->right = new Node(90);

    root = deleteNode(root, 90);

    print(root);

    return 0;
}
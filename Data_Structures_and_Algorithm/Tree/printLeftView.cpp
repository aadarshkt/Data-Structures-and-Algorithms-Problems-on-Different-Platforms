#include <bits/stdc++.h>
using namespace std;

// at every level you have to print leftmost of the binary tree.

struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};

int maxLevel = 0;

//Time complexity -> O(n), n is number of nodes.
//Space complexity -> theta(h), h is height of the tree.

void leftRecursive(Node *root, int level)
{
    if(root == NULL) return;

    if(maxLevel < level)
    {
        cout << root->data << " ";
        maxLevel = level;
    }

    if(root->left != NULL) leftRecursive(root->left, level + 1);
    if(root->right != NULL) leftRecursive(root->right, level + 1);

}

// Obvisoulsy we will use level order traversal.As we have to print first leftmost node in the tree.

//Time complexity - O(n)
//Space complexity - O(n)

void printLeftView(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int len = q.size();

        Node *curr;

        for (int i = 0; i < len; i++)
        {
            curr = q.front();
            if (i == 0)
            {
                cout << curr->data << " ";
            }
            q.pop();

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(70);

    printLeftView(root);

    cout << endl;

    leftRecursive(root, 1);

    return 0;
}
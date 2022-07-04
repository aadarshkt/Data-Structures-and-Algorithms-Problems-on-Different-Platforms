#include <bits/stdc++.h>
using namespace std;

//Time complexity --> theta(n) . we have a while loop which runs for every node.(see q.pop() -> it has to do exactly n times till it becomes empty)
//Space complexity --> O(n). at a time we have max only one level.  n -> node theta(width) width = n+1/2 for perfect binary tree.


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

//Use queue --> first in first out.

void levelOrder(Node *root)
{
    queue<Node *> q;//Important to learn;
    q.push(root);

    Node *front;

    while (q.empty() == false)
    {
        front = q.front();
        cout << front->data << " ";
        q.pop();

        if (front->left != NULL)
            q.push(front->left);

        if (front->right != NULL)
            q.push(front->right);
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

    levelOrder(root);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

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

//Time complexity --> O(n). 
//Space complexity --> O(n). or theta(width) width = (n+ 1)/2;

void levelOrderLineByLine(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    Node *front;

    while (q.size() > 1)
    {
        front = q.front();

        if (front == NULL)
        {
            cout << endl;
            q.push(NULL);
            q.pop();
            continue;
        }

        q.pop();

        cout << front->data << " ";
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

    levelOrderLineByLine(root);

    return 0;
}
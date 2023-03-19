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

// Horizontal distance can only be increased by a top view node.
void topView(Node *root)
{
    queue<pair<Node *, int>> q;
    stack<int> s;
    vector<int> v;

    
    q.push({root, 0});
    s.push(root->data);


    int hd = 0, max = 0, min = 0;

    while (q.empty() == false)
    {
        Node *first = q.front().first;
        hd = q.front().second;

        q.pop();

        if (hd < min)
        {
            min = hd;
            s.push(first->left->data);
        }

        if (hd > max)
        {
            max = hd;
            v.push_back(first->right->data);
        }

        if (first->left != NULL)
        {
            q.push({first->left, hd - 1});
        }
        if (first->right != NULL)
        {
            q.push({first->right, hd + 1});
        }
    }

    while (s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << root->data << " ";

    for (auto x : v)
    {
        cout << x << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    topView(root);

    return 0;
}
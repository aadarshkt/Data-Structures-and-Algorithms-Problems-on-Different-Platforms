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

// Efficient TC --> O(nlogn)
// order maintained.

void verticalTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    map<int, vector<int, int>> m;

    int hd = 0;

    while (q.empty() == false)
    {
        Node *fn = q.front().first;
        hd = q.front().second;

        m[hd].push_back(fn->data);

        if (fn->left != NULL)
            q.push({fn->left, hd - 1});
        if (fn->right != NULL)
            q.push({fn->right, hd + 1});
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        int n = it->second.size();
        for(int i=0; i<n; i++)
        {
            cout << it->second[i] << " ";
        }

        cout << endl;
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
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    root->right->right->left->right->right = new Node(12);

    verticalTraversal(root);

    return 0;
}
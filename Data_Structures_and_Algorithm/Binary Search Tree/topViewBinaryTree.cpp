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

void inorder(Node *root, map<int, int> &m, int hd)
{
    if (root == NULL)
        return;

    int rootValue = root->data;
    if (!m.count(rootValue))
        m[root->data] = hd;

    inorder(root->left, m, hd - 1);
    inorder(root->right, m, hd + 1);
}

void levelOrder(Node *root, set<int> &hds, map<int, int> &m, map<int, int> &ans)
{
    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();

        int hdData = m[curr->data];
        if (!hds.count(hdData))
        {
            ans[hdData] = curr->data;
            hds.insert(hdData);
        }
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

void topView(Node *root)
{
    map<int, int> m;

    inorder(root, m, 0);

    set<int> hds;

    map<int, int> ans;

    levelOrder(root, hds, m, ans);

    for(auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << it->second << " ";
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
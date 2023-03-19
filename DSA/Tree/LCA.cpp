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

//Good recursive function.

bool findPath(Node *root, vector<Node *> &p, int n)
{
    if(root == NULL) return false;

    p.push_back(root);

    if(root->data == n) return true;

    //Main statement returning true;
    if(findPath(root->left, p, n) || findPath(root->right, p, n))
        return true;

    p.pop_back();

    return false;
}

int lowestCommonAncestor(Node *root, int n1, int n2)
{
    vector<Node *> v1, v2;

    findPath(root, v1, n1);
    findPath(root, v2, n2);

    int len = min(v1.size(), v2.size());

    bool flag = true;

    int ans = 0;

    for(int i=0; i<len; i++)
    {
        if(v1[i] != v2[i]) 
        {
            flag = false;
            ans = v1[i-1]->data;
        }
    }

    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->left->left = new Node(60);
    root->right->right->left = new Node(70);
    root->right->right->right = new Node(80);

    cout << lowestCommonAncestor(root, 30, 80);

    return 0;
}
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

//recursive is always better.

//Time complexity --> O(n), n - node
//Space complexity --> O(h), h - height of binary tree

int maxRecursive(Node *root)
{
    if(root == NULL) return INT_MIN;

    return max({root->data, maxRecursive(root->left), maxRecursive(root->right)});
}

int maximumNode(Node *root)
{
    int maxNum = INT_MIN;

    queue<Node *> q;
    q.push(root);

    while(q.empty() == false)
    {
        //basically running for loop for every node in one level.
        int len = q.size();

        Node *curr;
        
        for(int i=0; i<len; i++)
        {
            curr = q.front();
            maxNum = max(maxNum, curr->data);
            q.pop();

            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
    }

    return maxNum;
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

    cout << maximumNode(root);
    cout << maxRecursive(root);

    return 0;
}
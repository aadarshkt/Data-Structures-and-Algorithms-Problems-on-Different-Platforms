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

//Time complexity --> O(n)
//Space complexity --> O(width)

int sizeOfBinaryTree(Node *root)
{
    queue<Node *> q;
    q.push(root);

    if(root == NULL) return 0;

    int len;

    int count = 0;

    while(q.empty() == false)
    {
        len = q.size();
        Node *curr;

        for(int i=0; i<len; i++)
        {
            curr = q.front();
            q.pop();

            count++;

            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
    }

    return count;
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

    cout << sizeOfBinaryTree(root);

    return 0;
}
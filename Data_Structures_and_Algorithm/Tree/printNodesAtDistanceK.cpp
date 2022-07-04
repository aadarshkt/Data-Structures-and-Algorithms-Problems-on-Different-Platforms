#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    public:
    Node(int x)
    {
        this->data = x;
        left = NULL;
        right = NULL;
    }
};

void printNodes(Node *root, int k, int i)
{
    if(i == k && root != NULL)
    {
        cout << root->data << " ";
        return;
    }
    
    if(root == NULL) return;

    i = i + 1;
    
    printNodes(root->left, k, i);
    printNodes(root->right, k, i);
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

    int k = 2;

    printNodes(root, k, 0);

    return 0;
}
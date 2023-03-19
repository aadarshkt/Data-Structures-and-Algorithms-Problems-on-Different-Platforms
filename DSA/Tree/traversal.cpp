#include <bits/stdc++.h>
using namespace std;

//Time complexity --> O(n) : n is the number of nodes.
//Auxiliary space --> O(h) //h is height of the binary tree.//h functions will be there in function call stack.(max)


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

void inorderTravsersal(Node *node)
{
    if(node == NULL)
        return;

    inorderTravsersal(node->left);
    cout << node->data << "->";
    inorderTravsersal(node->right);
}

void preorderTravsersal(Node *node)
{
    if(node == NULL)
        return;

    cout << node->data << "->";
    preorderTravsersal(node->left);
    preorderTravsersal(node->right);
}

void postorderTraversal(Node *node)
{
    if(node == NULL)
        return;
    
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << "->";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    cout << "inorder traversal ";
    inorderTravsersal(root);

    cout << endl;

    cout << "preorder traversal ";
    preorderTravsersal(root);

    cout << endl;

    cout << "postorderTravseral ";
    postorderTraversal(root);
    

    return 0;
}
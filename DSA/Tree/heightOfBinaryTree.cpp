#include <bits/stdc++.h>
using namespace std;

//Time complexity --> O(n) : n is number of nodes.
//Aux space --> O(h) : h is height of the tree.

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

int height(struct Node* node)
{
    //code here
    
    if(node == NULL) return 0;
    
    int h1 = 1 + height(node->left);
    int h2 = 1 + height(node->right);
    
    int res;
    
    res = h1 > h2 ? h1 : h2;
    
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    return 0;
}
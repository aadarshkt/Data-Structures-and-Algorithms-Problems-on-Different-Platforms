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

//You write this by imagining 10, 20, 30. focus on 20, 30

//Time complexity --> O(n), n - node in the tree.
//Space complexity --> theta(width), O(n)

void levelOrder(Node *root)
{
    queue<Node *> q;    
    q.push(root);

    int count;

    while(q.empty() == false)
    {
        count = q.size();
        Node *curr;

        for(int i=0; i<count; i++)
        {
            curr = q.front(); 
            cout << curr->data << " ";
            q.pop();

            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }

        cout << endl;
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

    levelOrder(root);

    return 0;
}
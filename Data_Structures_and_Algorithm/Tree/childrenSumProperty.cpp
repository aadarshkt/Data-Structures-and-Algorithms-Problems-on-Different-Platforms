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

//Time complexity --> O(n), n is no of nodes.
//Space complexity --> O(h), h is height.

bool isSum(Node *root)
{
    if(root == NULL) return true;

    int sum = 0;

    if(root->left == NULL && root->right == NULL) sum = root->data;

    if(root->left != NULL) sum += root->left->data;
    if(root->right != NULL) sum += root->right->data;

    return sum == root->data && isSum(root->left) && isSum(root->right);
}

bool checkChildrenSum(Node *root)
{
    if (root == NULL)
        return true;

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int len = q.size(); // imagine 20, 30

        int sum = 0, left, right;

        Node *curr;

        for (int i = 0; i < len; i++)
        {
            curr = q.front();
            q.pop();

            if(curr->left == NULL) left = 0;
            else left = curr->left->data;

            if(curr->right == NULL) right = 0;
            else right = curr->right->data;

            sum = left + right;

            if(curr->right == NULL and curr->left == NULL) sum = curr->data;

            if (sum != curr->data)
                return false;

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(5);


    cout << checkChildrenSum(root);

    cout << endl;

    cout << isSum(root);



    return 0;
}
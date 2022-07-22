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

// Not efficient.
// O(n^2)
void findMinMax(Node *root, int &min, int &max, int hd)
{
    if(root == NULL) return;

    if(hd < min) min = hd;
    else if(hd > max) max = hd;

    findMinMax(root->left, min, max, hd-1);
    findMinMax(root->right, min, max, hd+1);
}

void printVertical(Node *root, int lineNo, int hd)
{
    if(root == NULL) return;

    if(hd == lineNo) cout << root->data << " ";

    printVertical(root->left, lineNo, hd - 1);
    printVertical(root->right, lineNo, hd + 1);
}

void verticalOrder(Node *root)
{
    int min = 0, max = 0;
    findMinMax(root, min, max, 0);

    //for each vertical line traverse the whole tree.
    for(int i=min; i<max+1; i++)
    {
        printVertical(root, i, 0);
        cout << endl;
    }
}

//Efficient
//make a map from hd to vector, we traverse the tree once, and store all the value from hd to there corresponding nodes.

//Time complexity --> O(nLogn) why ? because insert to map takes logn time and it is running for every node.
//Order not maintained.
void verticalEfficient(Node *root, int hd, map<int, vector<int>> &m)
{
    if(root == NULL) return;

    //logn time based on self-balancing binary search tree.
    m[hd].push_back(root->data);

    verticalEfficient(root->left, hd-1, m);
    verticalEfficient(root->right, hd+1, m);
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

    // verticalOrder(root);


    map<int, vector<int>> m;

    verticalEfficient(root, 0, m);

    for(auto it = m.begin(); it != m.end(); it++)
    {
        int n = (it->second).size();

        for(int i=0; i<n; i++)
        {
            cout << it->second[i] << " ";
        }

        cout << endl;
    }

    //maintain order.Next solution to be done later.

    return 0;
}
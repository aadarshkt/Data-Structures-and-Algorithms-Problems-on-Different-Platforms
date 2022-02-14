#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *recursiveReverse(Node* prev, Node* curr)
{

    if(curr == NULL)
    {
        return prev;
    }
    

    Node* next = curr->next;
   
    curr->next = prev;
    prev = curr;
    curr = next;

    return recursiveReverse(prev, curr);

}

void print(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

int main()
{

    Node *head = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(20);
    Node *fourth = new Node(23);

    head->next = second;
    second->next = third;
    third->next = fourth;

    head = recursiveReverse(NULL, head);

    print(head);

    return 0;
}
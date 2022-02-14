#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *randomPointer;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void cloneLLRandom(Node* head)
{
    Node* curr = head;
 
    for(curr; curr != NULL; curr = curr->next)
    {
        
    }
}


void print(Node *n)
{
    int count = 0;
    while (n != NULL && count < 7)
    {
        cout << n->data << " ";
        n = n->next;
        count++;
    }
}
 
int main()
{

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    cloneLLRandom(head);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }

};

Node* deleteHead(Node* head)
{
    if(head == NULL)
    {
        return head;
    }

    Node* curr = head->next;

    delete head;

    return curr;
}

void print(Node* n)
{
    while(n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}
 
int main()
{

    Node* head = new Node(5);
    Node* second = new Node(15);
    Node* third = new Node(20);

    head->next = second;
    second->next = third;

    head = deleteHead(head);

    print(head);

    return 0;
}
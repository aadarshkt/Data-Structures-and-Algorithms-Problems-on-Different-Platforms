#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* next;
    Node* prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }

};

Node* insert(Node* head, int x, int pos)
{

    Node* curr = head;
    Node* NewNode = new Node(x);

    for(int i=0; i<pos-2; i++)
    {
        curr = curr->next;
    }

    if(pos == 1)
    {
        NewNode->next = head;
        return NewNode;
    }

    if(curr->next == NULL)
    {
        NewNode->prev = curr;
        curr->next = NewNode;
        return head;
    }

  

    NewNode->prev = curr;
    NewNode->next = curr->next;

    (curr->next)->prev = NewNode;
    curr->next = NewNode;

    return head;


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
    Node* third = new Node(25);

    head->next = second;
    second->next = third;
    second->prev = head;
    third->prev = second;

    int pos = 4;

    head = insert(head, 20, pos);

    print(head);

    return 0;
}
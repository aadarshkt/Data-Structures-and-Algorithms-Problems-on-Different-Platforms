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

Node* delete_Last(Node* head)
{
    Node* curr = head;

    while(curr->next->next != NULL)
    {
        curr = curr->next;
    }

    if(head == NULL)
    {
        return head;
    }

    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }

    delete curr->next;

    curr->next = NULL;

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
    Node* third = new Node(20);
    Node* fourth = new Node(23);
    Node* fifth = new Node(25);
    Node* sixth = new Node(30);

    
    fourth->next = fifth;
    fifth->next = sixth;

    head = delete_Last(head);


    print(head);

    return 0;
}
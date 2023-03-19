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

Node* insert_at_pos(Node* head, int pos, int x)
{
    Node* curr = head;

    if(pos == 1)
    {
        Node* NewNode = new Node(x);
        NewNode->next = curr->next;
        head = NewNode;
        return head;
    } else if(pos == 0)
    {
        Node* NewNode = new Node(x);
        NewNode->next = head;
        return NewNode;
    }

    for(int i=0; i<pos-2; i++)
    {
        if(curr == NULL)
        {
            return head;
        }
        curr = curr->next;
    }

    Node* NewNode = new Node(x);

    NewNode->next = curr->next;
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
    Node* third = new Node(20);
    Node* fourth = new Node(23);

    head->next = second;
    second->next = third;
    third->next = fourth;

    int x = 27;

    head = insert_at_pos(head, 0, x);
 
    print(head);

    return 0;
}
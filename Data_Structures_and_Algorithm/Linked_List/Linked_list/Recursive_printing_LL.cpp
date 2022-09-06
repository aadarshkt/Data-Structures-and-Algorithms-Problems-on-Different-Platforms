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

void print(Node *head)
{
    if(head == NULL)
    {
        return;
    }

    cout << head->data << " ";

    print(head->next);
}
 
int main()
{

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    
    head->next = second;
    second->next = third;
    third->next = NULL;

    print(head);
    

    return 0;
}
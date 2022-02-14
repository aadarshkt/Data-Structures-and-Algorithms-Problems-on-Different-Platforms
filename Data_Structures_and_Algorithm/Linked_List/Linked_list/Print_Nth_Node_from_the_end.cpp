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

void NthNodeFromEnd(Node* head, int pos)
{
    Node* temp2 = head;
    Node* temp1 = head;

    for(int i=0; i<pos-1; i++)
    {
        temp2 = temp2->next;
    }

    while(temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    cout << temp1->data;


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

    NthNodeFromEnd(head, 2);

    return 0;
}
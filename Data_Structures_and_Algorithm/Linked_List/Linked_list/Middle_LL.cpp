#include <bits/stdc++.h>
using namespace std;

//Based on slow and fast pointers.

struct Node{

    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }

};

void printMiddle(Node* head)
{
    Node* temp1 = head;
    Node* temp2 = head;

    while(true)
    {

        if(temp2->next == NULL)
        {
            cout << temp1->data << " ";
        } else if(temp2->next->next == NULL)
        {
            cout << temp1->data << " ";
        }

        temp1 = temp1->next;
        temp2 = temp2->next->next;

        
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

  

    printMiddle(head);

    return 0;
}
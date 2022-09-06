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

void printJunction(Node* h1, Node* h2)
{
    Node* curr1 = h1, *curr2 = h2;
    int lenOne = 0, lenTwo = 0;

    while(curr1 != NULL)
    {
        lenOne++;
        curr1 = curr1->next;
    } 

    while(curr2 != NULL)
    {
        lenTwo++;
        curr2 = curr2->next;
    } 

    int difference = lenOne - lenTwo;

    Node* tempOne = h1;
    Node* tempTwo = h2;

    if(difference > 0)
    {
        for(int i=0; i<difference; i++)
        {
            tempOne = tempOne->next;
        }
    } else 
    {
       
        difference = (-1) * (difference);   
        for(int i=0; i<difference; i++)
        {
            tempTwo = tempTwo->next;
        }
    }

    while(tempOne != tempTwo)
    {
        tempOne = tempOne->next;
        tempTwo = tempTwo->next;
    }

    cout << tempOne->data;

      
}
 
int main()
{

     Node *head = new Node(17);
    Node *second = new Node(19);
    Node *third = new Node(8);
    Node *fourth = new Node(10);
    Node *fifth = new Node(15);
    Node *sixth = new Node(20);
    Node *extra = new Node(35);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    
    extra->next = third;

    printJunction(head, extra);

    return 0;
}
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


void printCircular(Node* head)
{

    while(head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << head->data << " ";

}

Node* insertInSorted(Node* head, int x)
{
    Node* temp = head;
    Node* newNode = new Node(x);

    if(head == NULL)
    {
        return newNode;
    }

    if(head->data > x)
    {
        newNode->next = head;
        return newNode;
    }

    //first part of while loop is important we cannot access the data if temp->next == NULL
     
    while(temp->next != NULL && temp->next->data <= x)
    {
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        temp->next = newNode;
        return head;
    }

    

    Node* secondNext = temp->next;

    temp->next = newNode;
    newNode->next = secondNext;

    return head;
}
 
int main()
{

    Node* head = new Node(5);
    Node* second = new Node(15);
    Node* third = new Node(25);
    Node* fourth = new Node(35);

    head->next = second;
    second->next = third;
    third->next = fourth;

    int x = 200;

    head = insertInSorted(head, x);

    printCircular(head);
    return 0;
}
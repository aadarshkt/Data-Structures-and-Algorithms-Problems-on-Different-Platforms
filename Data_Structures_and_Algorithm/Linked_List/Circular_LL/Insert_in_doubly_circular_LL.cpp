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
    }

};


void printCircular(Node* head)
{
    Node* temp = head;
    do{
        cout << head->data << " ";
        head = head->next;
    } while(head->next != temp);

    cout << head->data << " ";

}

Node* insertDoubleCircular(Node* head, int pos, int x)
{
    Node* temp = head;

    Node* newNode = new Node(x);


    if(pos == 1)
    {
        Node* last = head->prev;
        last->next = newNode;

        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;

        return newNode;

    }

    for(int i=0; i<pos-2; i++)
    {
        temp = temp->next;
    }

    Node* secondNext = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = secondNext;
    secondNext->prev = newNode;

    return head;
}
 
int main()
{

    Node* head = new Node(5);
    Node* second = new Node(15);
    Node* third = new Node(20);
    Node* fourth = new Node(25);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    second->prev = head;
    third->prev = second;
    fourth->prev = third;
    head->prev = fourth;

    int pos = 1;

    head = insertDoubleCircular(head, pos, 55);

    printCircular(head);

    

    return 0;
}
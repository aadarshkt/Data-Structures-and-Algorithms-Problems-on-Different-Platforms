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

Node* circular(Node* head)
{
    Node* curr = head;

    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = head;

    return head;
}

void printCircular(Node* n)
{
    Node* temp = n;
    Node* curr = n;
    while(curr->next != temp)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    
    cout << curr->data << " ";
}

void printCircularDOWhile(Node* head)
{
    Node* temp = head;

    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);

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

    circular(head);


    printCircular(head);

    cout << endl;

    printCircular(head);

 
 

    return 0;
}
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

Node* delete_node(Node* head, int pos)
{

    Node* curr = head;

    if(head == NULL)
    {
        return NULL;
    }

    if(pos == 1 && head->next == NULL)
    {
        delete head;
        return NULL;
    }

    if(pos == 1)
    {
        Node* temp = curr->next;
        temp->prev = NULL;
        delete head;
        return temp;
    }

    for(int i=0; i<pos-2; i++)
    {
        curr = curr->next;
    }


    Node* temp = curr->next;

    if(temp->next == NULL)
    {
        curr->next = NULL;
        delete temp;
        return head;
    }

    curr->next = temp->next;
    (temp->next)->prev = curr;

    delete temp;
   
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
    Node* fourth = new Node(25);

    head->next = second;
    second->next = third;
    second->prev = head;
    third->next = fourth;
    third->prev = second;
    fourth->prev = third;

    int pos = 4;

    head = delete_node(head, pos);

    print(head);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node{

    //Node will have two properties one will be data and other will be a pointer;

    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }

};

Node* insert_at_the_end(Node* head, int x)
{
     Node* NewNode = new Node(x);//Ways to create new object of struct node.
    if(head == NULL)//when we say n == NULL we say it for data//n is address of the NULL 
    {
        return NewNode; 
    }

    //n is the variable that stores the address of the data;but this variable will have two properties n->data and n->next (stores the address of the next node.)

    Node* curr = head;

    while(curr->next != NULL)
    {
        curr = curr->next;
    }

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

    Node* head = NULL;//a value that is nothing

    head = insert_at_the_end(head, 20);
    head = insert_at_the_end(head, 30);

    //In case the chain has already one or more elements

    // Node* head = new Node(5);
    // Node* second = new Node(10);

    // head->next = second;
    // second->next = insert_at_the_end(20);


    print(head);

    return 0;
}
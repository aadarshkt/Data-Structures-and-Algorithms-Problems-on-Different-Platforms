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

void printList(Node* n)
{
    while(n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node* insert_at_begin(Node* head, int x)
{
    Node* NewNode = new Node(x);//Like    int *arr = new int[5]; //That's why it is called a data structure;

    NewNode->next = head;

    return NewNode;

}

int main()
{

    
    Node* head = NULL;
 
    head = insert_at_begin(head, 5);
    head = insert_at_begin(head, 10);
    head = insert_at_begin(head, 20);
    head = insert_at_begin(head, 30);

    printList(head);


    return 0;
}
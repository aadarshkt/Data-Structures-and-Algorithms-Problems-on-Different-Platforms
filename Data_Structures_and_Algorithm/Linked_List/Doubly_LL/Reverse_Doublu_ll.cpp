#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* next;
    Node* prev;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }

};

Node* reverse(Node* head)
{
    Node* temp;

    while(head->next != NULL)
    {
        temp = head->prev;
        head->prev = head->next;
        head->next = temp;
        head = head->prev;
    }
    
    Node* curr = head->prev;

    head->next = curr;
    head->prev = NULL;

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

    head = reverse(head);

    print(head);

    return 0;
}
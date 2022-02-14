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

Node* insertCircular(Node* head, int pos, int x)
{
    
}

void printCircular(Node* head)
{
    Node* temp = head;
    do{
        cout << head->data << " ";
        head = head->next;
    } while(head->next != temp);

    cout << head->data << " ";

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

    head = insertCircular(head, 1, 55);

    printCircular(head);

    return 0;
}
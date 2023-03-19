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
    Node* curr = head;
    Node* NewNode = new Node(x);

    for(int i=0; i<pos-2; i++)
    {
        curr = curr->next;
    }

    if(pos == 1)
    {
        NewNode->next = head;
        do{
            curr = curr->next;
        } while(curr->next != head);

        curr->next = NewNode;

        return NewNode;

    }


     NewNode->next = curr->next;
     curr->next = NewNode;
    

    return head;


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

    head = insertCircular(head, 5, 55);

    printCircular(head);

    return 0;
}
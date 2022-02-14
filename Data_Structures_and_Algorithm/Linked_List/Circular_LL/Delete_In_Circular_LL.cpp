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

Node* delete_link(Node* head, int pos){

    Node* temp = head;


    if(head->next == NULL)
    {
        return NULL;
    }


    for(int i=0; i<pos-2; i++)
    {
        temp = temp->next;
    }

    if(pos == 1)
    {
        


        do{
            temp = temp->next;
        } while(temp->next != head);

        temp->next = head->next;

        delete head;
        return temp->next;
    }

    Node* nodeToBeDeleted = temp->next;

    temp->next = temp->next->next;

    delete nodeToBeDeleted;

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

    head = delete_link(head, 4);

    printCircular(head);

    return 0;
}
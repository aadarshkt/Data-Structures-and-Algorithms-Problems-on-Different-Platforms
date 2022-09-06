#include <bits/stdc++.h>
using namespace std;

//Good 
//The first arugment of while loop is imp. because at last curr becomes null if again while loop runs we cannot check whether curr->next is null or not 
//Else part is also imp otherwise we cannot delete three nodes having same values.
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* removeDuplicates(Node* head)
{
    Node* curr = head;

    int count = 0;
 
    while(curr != NULL && curr->next != NULL)
    {
        if(curr->data ==  curr->next->data)
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }  else {
            curr = curr->next;
        }

        
    }

    cout << count << endl;

   
    return head;
}

void print(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
 

}
 
int main()
{

    
    Node *head = new Node(5);
    Node *second = new Node(5);
    Node *third = new Node(5);
    Node *fourth = new Node(23);

    head->next = second;
    second->next = third;
    third->next = fourth;

    head = removeDuplicates(head);

    print(head);

    return 0;
}
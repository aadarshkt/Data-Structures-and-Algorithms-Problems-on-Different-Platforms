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

Node* reverse_LLNaive(Node* head)
{
    vector<int> arr;

    for(Node* curr = head; curr != NULL; curr = curr->next)
    {
        arr.push_back(curr->data);
    }

    for(Node* curr = head; curr != NULL; curr = curr->next)
    {
        curr->data = arr.back();
        arr.pop_back();
    }

    return head;
}

//We maintain two pointer Node.

Node* reverse_LL(Node* head)
{
    Node* prev = head;
    Node* curr = head->next;

    prev->next = NULL;

    Node* next;
 
    while(curr != NULL)
    { 
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
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
    Node* fourth = new Node(23);

    head->next = second;
    second->next = third;
    third->next = fourth;

    head = reverse_LL(head);

    print(head);


    return 0;
}
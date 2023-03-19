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
 
int main()
{

    Node* head = new Node(5);
    Node* second = new Node(15);
    Node* third = new Node(25);

    head->next = second;
    second->next = third;
    second->prev = head;
    third->prev = second;
     

    return 0;
}
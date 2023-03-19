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

void print(Node* n)
{
    while(n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

int find(Node* head, int x)
{
    Node* curr = head;

    int count = 1;

    while(curr != NULL)
    {
        if(curr->data == x)
        {
            return count;
        }
        curr = curr->next;
        count++;
    }

    return -1;
}

//Recursive solution

int find_rec(Node* head, int x, int y)
{
    y++;
    if(head == NULL)
    {
        return -1;
    }
    if(head->data == x)
    {
        return y;
    } 

    return find_rec(head->next, x, y);
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

    cout << find(head, 5) << endl;
    int y = 0;
    cout << find_rec(head, 30, y);

    return 0;
}
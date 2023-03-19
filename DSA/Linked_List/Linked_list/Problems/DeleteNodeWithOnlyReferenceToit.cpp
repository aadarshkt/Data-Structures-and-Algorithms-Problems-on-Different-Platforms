#include <bits/stdc++.h>
using namespace std;

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

Node *deleteNode(Node *startNode)
{
    Node *curr = startNode;
    Node *next = startNode->next;

    //Basically we have to stop(doing incrementation) when node is at second-last and last position respectively.

    do
    {
        swap(curr->data, next->data);
        if (next->next != NULL)
        {
            curr = curr->next;
            next = next->next;
        }

    } while (next->next != NULL);

    curr->next = NULL;
    delete (next);

    return startNode;
}

void print(Node *n)
{
    int count = 0;
    while (n != NULL && count < 7)
    {
        cout << n->data << " ";
        n = n->next;
        count++;
    }
}

int main()
{

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;

    deleteNode(third);

    print(head);

    return 0;
}
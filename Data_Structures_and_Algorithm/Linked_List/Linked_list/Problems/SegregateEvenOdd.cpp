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

Node *segregate(Node *head)
{
    Node *es = NULL, *ee = NULL, *os = NULL, *oe = NULL;

    Node *curr = head;

    while (curr != NULL)
    {
        int num = curr->data;
        if (num % 2 == 0)
        {
            if (es != NULL)
            {

                ee->next = curr;
                ee = ee->next;
            }
            else
            {
                es = curr;
                ee = es;
            }
        }
        else
        {

            if (os != NULL)
            {

                oe->next = curr;
                oe = oe->next;
            }
            else
            {
                os = curr;
                oe = os;
            }
        }

        curr = curr->next;
    }

    if(os == NULL || oe == NULL)
    {
        return head;
    }

    ee->next = os;
    oe->next = NULL;

    return es;
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

    Node *head = new Node(17);
    Node *second = new Node(19);
    Node *third = new Node(8);
    Node *fourth = new Node(10);
    Node *fifth = new Node(15);
    Node *sixth = new Node(20);
    Node *seventh = new Node(35);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    head = segregate(head);
    print(head);

    return 0;
}
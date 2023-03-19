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

Node *swapNodes(Node *head)
{
    Node *tempOne = head, *tempTwo = head->next;

    //handle for only one node
    if(tempTwo == NULL)
    {
        return head;
    }

    Node *secondNext, *firstNext;

    Node *startingNode = head->next;


    //handle for only two nodes.
    if(tempTwo->next == NULL)
    {
        tempTwo->next = tempOne;
        tempOne->next = NULL;
        return startingNode;
    }

    
    while (tempTwo->next != NULL)
    {
        firstNext = tempTwo->next;
       
        if (firstNext->next == NULL)
        {
            //handling for odd nodes
            tempTwo->next = tempOne;
            tempOne->next = firstNext;
            break;
        }
        
        secondNext = tempTwo->next->next;

        

        tempTwo->next = tempOne;
        tempOne->next = secondNext;

        tempTwo = secondNext;
        tempOne = firstNext;
    }

    if (firstNext->next != NULL)
    {
        //when odd all computation is completed in the while loop only so handling below for even nodes.
        tempTwo->next = tempOne;
        tempOne->next = NULL;
    }

    return startingNode;
}

Node *swapNodesNaive(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        Node *next = curr->next;
        swap(curr->data, next->data);

        curr = curr->next->next;
    }

    return head;
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
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

 

    // head = swapNodesNaive(head);

    // print(head);

    head = swapNodes(head);

    print(head);

    return 0;
}
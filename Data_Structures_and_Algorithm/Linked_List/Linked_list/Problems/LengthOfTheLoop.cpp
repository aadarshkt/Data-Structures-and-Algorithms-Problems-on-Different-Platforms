#include <bits/stdc++.h>
using namespace std;

//we also find the junction and length of the loop.

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

void lengthOfTheLoop(Node* head)
{
    Node *slow = head, *fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    } while(slow != fast && fast != NULL && fast->next != NULL);

    if(slow == fast)
    {
        slow = head;

        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        Node* junction = slow;

        cout << "The junction is " << junction->data << endl;

        int count = 1;

        do{
            count++;
            fast = fast->next;
        }while(fast->next != junction);

        cout << "The length of the loop is " << count << endl;
    }  else 
    {
        cout << "No Loop found" << endl;
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
    fourth->next = second;

    lengthOfTheLoop(head);

    return 0;
}
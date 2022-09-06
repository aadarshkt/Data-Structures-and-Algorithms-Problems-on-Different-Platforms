#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;

    Node(char x)
    {
        data = x;
        next = NULL;
    }
};

void palindrome(Node* head)
{
    Node* curr = head;
    Node* temp = head;

    int count = 0;

    unordered_set<char> s;

    for(curr; curr != NULL; curr = curr->next)
    {
        s.insert(curr->data);
    }

    for(temp; temp != NULL; temp = temp->next)
    {
        if(s.count(temp->data))
        {
            count++;
        }
    }

    int set_size = s.size();

    if(count == ((set_size * 2) - 1) || count == (set_size * 2)){

        cout << "Yes it is a Palindrome";

    } else {
        cout << "It is not a palindrome";
    }


}

//Efficient solution is based on following steps.

//1-> Find middle node 
//2-> Reverse all nodes to the next of it.
//3-> Compare everthing to the next of middle.

Node* middleNode(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
}

void palindromeEfficient(Node* head)
{
    Node* middle = middleNode(head);
}
 
int main()
{

    Node *head = new Node('R');
    Node *second = new Node('a');
    Node *third = new Node('d');
    Node *fourth = new Node('a');
    Node *fifth = new Node('r');

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;


    palindrome(head);

    palindromeEfficient(head);

    return 0;
}
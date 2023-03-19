#include <bits/stdc++.h>
using namespace std;

//Use slow fast approach..
//Floyd' detection method.

//1-> make two pointers one fast and one slow, fast will move two times faster than slow.
//2-> Thus Faster will enter the loop first, slower second.
//3-> When slower will also enter the loop, it is sure that faster will meet slower. Imagine a loop in which one is slower and one is faster.They will 100% meet.
//4-> When they meet intialise one (here slow) at starting position(head).
//5-> Now move them at same pace. If they meet They is loop junction position.

//But in this problem we will stop at 3 step. Because loop is detected.

//Method - 2 Hashing.

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

void print(Node *n)
{
    int count = 0;
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
        count++;
    }
}

//Floyd's Cycle Detection
//O(n) space and O(n) time.

void detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    if(head == NULL)
    {
        cout << "No Loop found";
    }

    do
    {
        slow = slow->next;
        fast = fast->next->next;

    } while (slow != fast && fast->next != NULL && fast != NULL);

    if (slow == fast)
    {
        cout << "Loop found";
    }
    else
    {
        cout << "No Loop found";
    }
}

//Efficient.//O(n) time but O(n) space. 

void detectLoopHashing(Node* head)
{
    Node* curr = head;

    unordered_set<int> s;

    while(curr != NULL)
    {
        s.insert(curr->data);
        curr = curr->next;
        //checking in set.
        if(s.count(curr->data))
        {
            cout << "Loop Found" ;
            break;
        }
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
    Node* eight = new Node(80);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;

    eight->next = fourth;

    detectLoop(head);
    cout << endl;
    detectLoopHashing(head);

    return 0;
}
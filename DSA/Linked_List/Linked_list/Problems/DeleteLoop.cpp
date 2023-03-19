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

//FLoyd detection algo.

Node* deleteLoop(Node *head)
{
    Node *slow = head, *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;

    } while (slow != fast && fast != NULL && fast->next != NULL);//order of fast and fast->next is also imp.

    if(slow != fast || fast == NULL)
    {
        cout << "No Loop" << endl;
        return head;
    } else {

        slow = head;

        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    
    Node* junction = slow;

    cout << "The junction is" << junction->data << endl;

    do{
        fast = fast->next;
    }while(fast->next != junction);


    fast->next = NULL;

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
 

    head->next = second;
 

    head = deleteLoop(head);

    print(head);

    return 0;
}
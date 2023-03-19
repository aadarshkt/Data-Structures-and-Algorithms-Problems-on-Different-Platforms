#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
      int data;//Basically you can imagine two boxes one stores data and other is pointer 
      Node* next;//Node is used because there is self referential structures and data type of next node is int.

      Node(int x)
      {
          data = x;
          next = NULL;
      }

};

void printList(Node* n)
{
    while(n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

void printPointer(int *n)
{
    *n = 20;

    cout << *n << endl;
}
 
int main()
{

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    

    head->next = second;///head next means |1|address| the address part represents the next and has the address of the second data is stored in next;


    second->next = third;

    third->next = NULL;

    printList(head);

    cout << endl;
    printList(head);//Head is not changed wow it is used like varibles.

    cout << endl;

    int i = 10;

    printPointer(&i);

    cout << i << endl; //But here it is different

    cout << second->data << " ";
    

    return 0;
}
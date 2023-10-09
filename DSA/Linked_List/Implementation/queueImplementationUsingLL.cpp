#include <bits/stdc++.h>
using namespace std;

struct QNode { 
    int val;
    QNode *next;
    QNode(int x){
        val=x;
        next=NULL;
    }
};

struct Queue { 
    QNode *front, *rear;
    Queue(){
        front=NULL,rear=NULL;
    }
    void push(int x){
        QNode *temp = new QNode(x);
        if(rear==NULL){
            front=rear=temp;
            return;
        }
        rear->next=temp;//change rear when pushing
        rear=rear->next;
    }
    void pop(){
        if(front==NULL)return;
        QNode *temp=front;
        front=front->next;//change front when popping.
        delete(temp);
        if(front==NULL)rear=NULL;
    }
    bool isEmpty(){
        if(front==NULL)return true;
        return false;
    }
    int getFront(){
        if(front==NULL)return NULL;
        return front->val;
    }
};

int32_t main()
{


    

    return 0;
}
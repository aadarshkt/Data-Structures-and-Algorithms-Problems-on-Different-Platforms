#include <bits/stdc++.h>
using namespace std;


class Queue{

    int capacity, size, front, rear;
    int *a;
    public: 
        Queue(int cap){
            capacity = cap;
            size = 0;
            front = 0, rear = cap - 1;
            a = new int[cap];
        }
        int enqueue(int x){
            if(size == capacity)return -1;
            rear = (rear + 1) % capacity;
            size++;
            a[rear] = x;
            return a[rear];
        }
        int dequeue(){
            if(size == 0)return -1;
            front = (front + 1) % capacity;
            size--;
            return a[front];
        }
        bool isEmpty(){
            if(size == 0)return true;
            return false;
        }
        bool isFull(){
            if(size == capacity)return true;
            return false;
        }
        int get_front(){
            if(size == 0)return -1;
            return a[front];
        }
        int get_rear(){
            if(size == 0)return -1;
            return a[rear];
        }

};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Queue q(100);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout<<"Q front is "<<q.get_front()<<'\n';
    cout<<"Q back is "<<q.get_rear()<<'\n';
    cout<<"Q is empty or not"<<q.isEmpty()<<'\n';

    q.dequeue();

    cout<<"Q front"<<q.get_front()<<'\n';

    q.dequeue();

    cout<<"Q front"<<q.get_front()<<'\n';



    return 0;
}
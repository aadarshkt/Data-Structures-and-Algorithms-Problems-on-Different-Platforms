#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

//push
//pop
//isEmpty
//peek

class Stack{
    int top;
    int a[1000];

    public:
        Stack(){
            top = -1;
        }

        int push(int x){
            if(top>=999)return -1;
            top++;
            a[top]=x;
            return a[top];
        }

        int pop(){
            if(top==-1)return -1;
            return a[top--];
        }

        bool isEmpty(){
            return top == -1;
        }

        int peek(){
            if(top==-1)return -1;
            return a[top];
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack\n"; 
    
    //print top element of stack after popping 
    cout << "Top element is : " << s.peek() << endl; 

    //print all elements in stack : 
    cout <<"Elements present in stack : "; 
    while(!s.isEmpty()) 
    { 
        // print top element in stack 
        cout << s.peek() <<" "; 
        // remove top element in stack 
        s.pop(); 
    } 


    return 0;
}
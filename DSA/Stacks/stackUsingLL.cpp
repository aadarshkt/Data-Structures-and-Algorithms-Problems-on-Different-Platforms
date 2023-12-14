#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

struct SNode{
    int val;
    SNode* next;
    SNode(int x){
        val = x;
        next = NULL;
    }
};

struct Stack{
    SNode* top;
    Stack(){
        top = NULL;
    }
    int push(int x){
        SNode* temp = new SNode(x);
        if(top==NULL){
            top = temp;
            return x;
        }else{
            temp->next = top;
            top = temp;
        }
        return top->val;
    }

    int pop(){
        if(top==NULL)return -1;
        SNode* temp = top;
        int popped = temp->val;
        top = top->next;
        free(temp);
        return popped;
    }

    bool isEmpty(){
        if(top==NULL)return true;
        return false;
    }

    int peek(){
        if(top==NULL)return -1;
        return top->val;
    }

};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Stack s;
    s.push(10);
    s.push(20);
    cout<<s.peek()<<'\n';
    s.pop();
    cout<<s.peek()<<'\n';

    return 0;
}
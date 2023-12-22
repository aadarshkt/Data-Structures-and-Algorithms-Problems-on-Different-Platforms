#include <bits/stdc++.h>
using namespace std;

class P1{
    public:
        void print(){
            cout<<"Hello parent"<<'\n';
        }
};

class c1 : public P1 {
    public:
        void print(){
            cout<<"hello c1"<<'\n';
        }
};

class c2 : public P1 {
    public:
        void print(){
            cout<<"hello c2"<<'\n';
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    c2 child2;
    child2.print();

    return 0;
}
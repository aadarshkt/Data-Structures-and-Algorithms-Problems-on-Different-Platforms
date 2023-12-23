#include <bits/stdc++.h>
using namespace std;

class base{
    public:
        virtual void fun(int x = 5){
            cout<<"The value from base class is "<<x<<'\n';
        }
};

class derived : public base{
    public:
        void fun(int x = 10){
            cout<<"The value from derived class is "<<x<<'\n';
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    base* bp = new derived;

    //default value from base class but function call of derived class.
    //default value is decided at compile time.
    bp->fun();

    return 0;
}
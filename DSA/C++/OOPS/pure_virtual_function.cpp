#include <bits/stdc++.h>
using namespace std;

//virtual function whose implementation is provided in derived class only.

class base {
    public:
        //pure virtual function.
        virtual void fun() = 0;
};

class derived : public base {
    public:
        void fun(){
            cout<<"derived fun is called"<<'\n';
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //abstract class cannot be instantiated.
    // base new_base;

    base* bp = new derived();
    bp->fun();

    return 0;
}
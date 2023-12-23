#include <bits/stdc++.h>
using namespace std;

class base {
    public:
        virtual void fun(){
            cout<<"base class"<<'\n';
        }
};

class derived : public base {
    public:
        void fun(){
            cout<<"derived class"<<'\n';
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    derived* d1 = new derived();

    d1->fun();

    base* b1 = dynamic_cast<base*>(d1);

    b1->fun();

    return 0;
}
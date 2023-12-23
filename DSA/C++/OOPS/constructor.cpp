#include <bits/stdc++.h>
using namespace std;

class base{
    private:
        int val;
    public:
        base(){
            cout<<"base class constructor called "<<'\n';
        }
        base(int x) : val(x) { }
        void print(){
            cout<<val<<'\n';
        }
        virtual ~base(){
            cout<<"base class destructor called "<<'\n';
        }
};

class derived : public base {
    public:
        derived(){
            cout<<"derived class constructor called"<<'\n';
        }
        ~derived(){
            cout<<"derived class destructor called "<<'\n';
        }
};

//no destructor of derived called.
//use virtual in base class to correctly call destructor of derived class.
// derived* d1 = new derived();
//     base* b1 = d1;
//     delete b1;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    derived* d1 = new derived();
    base* b1 = d1;
    delete b1;

    return 0;
}
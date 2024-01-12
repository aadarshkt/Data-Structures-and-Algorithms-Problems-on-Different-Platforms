#include <bits/stdc++.h>
using namespace std;

class base {
    public:
        virtual void fun(){
            cout<<"base class called"<<'\n';
        }
};

class derived : public base {
    private: 
        void fun(){
            cout<<"derived class called"<<'\n';
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //how to call private fun of derived???
    //use run time polymorphism which binds to fun of derived at run - time using 
    //base class pointer.

    base* bp = new derived(); //bp altough of type base* but contains the address of derived object.

    bp->fun(); //run time binding with derived class. //private function of derived accessed.
    

    return 0;
}
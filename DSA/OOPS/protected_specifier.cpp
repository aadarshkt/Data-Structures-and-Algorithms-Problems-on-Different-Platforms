#include <bits/stdc++.h>
using namespace std;

class Parent{
    protected:
        int a = 5;
};

class child : public Parent {
    protected: 
        child() { 
            cout<<"Child instantiation "<<a<<'\n';
        }
};

class grand_children : child {
    public:
    grand_children() {
        cout<<"grand_child instantiation "<<a<<'\n';
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    grand_children gd = grand_children();


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Parent{
    public:
        int speed = 10;
};

//second keyword in inheriated class.

//if it is public
//public -> public
//protected -> protected
//private -> private

//if it is private
// public, protected, private -> private

//if it is protected
//public and protected -> protected.
//private -> private

class child : public Parent{
    public:
        void my_parents_speed(){
            cout<<"My parent's speed is "<<speed<<'\n';
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    child c1;
    c1.my_parents_speed();
    cout<<c1.speed<<'\n';

    return 0;
}
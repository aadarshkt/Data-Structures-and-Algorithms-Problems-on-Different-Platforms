#include <bits/stdc++.h>
using namespace std;

class Parent{
    protected:
        int speed;
    public:
        void find_speed(){
            cout<<"I can run at "<<speed<<" m/s"<<'\n';
        }
        Parent(int s){
            speed=s;
        }
};

//called overloading
class child1 : public Parent{
    protected: 
        int speed;
    public:
        void find_speed(){
            cout<<"I can run at "<<speed<<" m/s"<<'\n';
        }
        child1(int s,int s1) : Parent(s1){
            speed=s;
        }
        //find speed of parent
        void find_speed_of_parent(){
            Parent::find_speed();
        }
};

class child2 : public Parent{
    protected:
        int speed;
    public:
        void find_speed(){
            cout<<"I can run at "<<speed<<" m/s\n";
        }
        child2(int s,int s1) : Parent(s1){
            speed = s;
        }
};


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Parent p1(10);
    child1 c1(15,11);
    child2 c2(20,12);

    c1.find_speed();
    c2.find_speed();
    p1.find_speed();

    //how to access 11 value of parent's speed of c1.
    c1.find_speed_of_parent();

    return 0;
}
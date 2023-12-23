#include <bits/stdc++.h>
using namespace std;

class Parent{
    public:
        virtual void print(){
            cout<<"Parent is called"<<'\n';
        }
        virtual void fun(){
            cout<<"base class called"<<'\n';
        }
};

class child1 : public Parent{
    private:
        //even if you make overriden version private but original virtual function of base
        //class is public then derived version will be called
        void print(){
            cout<<"Child is called "<<'\n';
        }
    public:
        void fun(int x){
            cout<<"The value of the derived is "<<x<<'\n';
        }
};

class child2 : public Parent{
    public:
        void print(){
            cout<<"child 2 is called"<<'\n';
        }
};

class child3 {
    public:
        void print(){
            cout<<"Hello"<<'\n';
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Parent* p1 = new Parent();
    p1->print();

    child1 c1;

    //binding to parent only. without virtual and override.
    p1 = &c1; //assignment operator works with derived class only.

    p1->print();
    //p1->fun(5) will not work because there is base class version of fun(int x)
    p1->fun();


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Animal{
    public: 
        virtual void make_sound(){
            cout<<"Generic animal sound"<<'\n';
        }
};

//called overriding
class Dog : public Animal{
    public:
        void make_sound() override{
            cout<<"Bhaw Bhaw"<<'\n';
        }
};

class Cat : public Animal{
    public:
        void make_sound() override{
            cout<<"Meow Meow"<<'\n';
        }
};

//without virtual and override keyword binding method to ptr variable is not changing
//it remains same as compile time value.

//when virtual and overrid keyword is used binding method is decided at runtime.

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Animal* ptr = new Animal();
    ptr->make_sound();
    cout<<ptr<<'\n';

    Dog dog;
    ptr = &dog;
    ptr->make_sound();
    cout<<ptr<<'\n';

    Cat cat;
    ptr = &cat;
    ptr->make_sound();
    cout<<ptr<<'\n';

    

    return 0;
}
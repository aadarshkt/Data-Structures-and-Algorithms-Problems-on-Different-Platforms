#include <bits/stdc++.h>
using namespace std;

//copy constructor must to create new dynamic memory

class rectangle{
    private:
        int length;
        int* breadth;
        //when copying using assignment or copy constructor
        //pointer values are copied thus memory location remains same.
        //so using new pointer when using copy constructor.
    public:
        rectangle(int len, int brea){
            length = len;
            breadth = new int;
            *breadth = brea;
        }
        rectangle(const rectangle& obj){
            length = obj.length;
            breadth = new int;
            *breadth = *obj.breadth;
        }
        void change_breadth(int x){
            *breadth = x;
        }
        int get_breadth(){
            return *breadth;
        }
        void set_breadth(int x){
            *breadth = x;
        }
        //this destructor is also necessary, as freeing up dynamically allocated memory
        //should be freed by programmer.
        ~rectangle(){
            delete breadth;
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    rectangle r1(10, 15);
    rectangle r2 = r1;//automatically overloaded operator...to copy using copy constructor.
    //our copy constructor uses deep copy code.

    r1.change_breadth(20);

    //deep copy.
    cout<<"The breadth of r2 is "<<r2.get_breadth()<<'\n';

    return 0;
}
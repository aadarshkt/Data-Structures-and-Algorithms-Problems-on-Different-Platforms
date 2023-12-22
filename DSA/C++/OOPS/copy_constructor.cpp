#include <bits/stdc++.h>
using namespace std;

//initialise new object on the basis of old object.
//assignment operator can also be used.

class C1{
    private:
        int a;
    public:

        C1(){

        }
        void init(int x){
            a = x;
        }
        void display(){
            cout<<a<<'\n';
        }
        // optional
        //calling by reference is important.
        C1(const C1& obj){
            this->a = obj.a;
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    C1 c1;
    c1.init(5);
    cout<<"First value with copy constructor "; c1.display();
    cout<<'\n';

    C1 c2(c1);
    cout<<"a value with copy constructor ";c2.display();
    cout<<'\n';



    return 0;
}
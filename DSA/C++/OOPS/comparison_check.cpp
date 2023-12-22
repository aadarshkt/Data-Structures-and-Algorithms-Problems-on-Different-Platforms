#include <bits/stdc++.h>
using namespace std;

class C1{
    private:
        int a;
    public:
        C1(int x){
            a = x;
        }
        bool operator== (const C1& obj){
            return this->a == obj.a;
        }
};


//simple equality operator doesn't work
//use operator overloading.

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    C1 c1(5);
    C1 c2(10);

    if(c1 == c2){
        cout<<"Yes"<<'\n';
    }else cout<<"No"<<"\n";

    //but assignment operator is automatically overloaded.

    C1 c3 = c2; //assignment operator works fine.

    return 0;
}
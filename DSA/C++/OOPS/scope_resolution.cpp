#include <bits/stdc++.h>
using namespace std;

class C1{
    private:
        void print();
    public:
        C1(){
            print();
        }
};

//using scope resolution define functions outside classes.
void C1::print(){
    cout<<"hello"<<'\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    C1 c1;

    return 0;
}
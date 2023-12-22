#include <bits/stdc++.h>
using namespace std;

class C1{
    protected:
        int a = 5;
};

class C2 : protected C1{
    protected:
        void print(){
            cout<<a<<'\n';
        }
};

class C3 : protected C2 {
    public:
    void print(){
        cout<<a<<'\n';
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    C3 o1;
    o1.print();

    return 0;
}
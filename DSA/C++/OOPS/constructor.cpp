#include <bits/stdc++.h>
using namespace std;

class C1{
    private:
        int val;
    public:
        C1(int x) : val(x) { }
        void print(){
            cout<<val<<'\n';
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    C1 o1(5);
    o1.print();

    return 0;
}
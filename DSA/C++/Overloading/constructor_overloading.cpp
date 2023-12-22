#include <bits/stdc++.h>
using namespace std;

class C1{
    private:
        int area = 0;
    public:
        C1(){
            area = 0;
        }
        C1(int a, int b){
            area = a * b;
        }
        void print(){
            cout<<area<<'\n';
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    C1 c1;
    C1 c2(5, 6);

    c1.print();
    c2.print();

    return 0;
}
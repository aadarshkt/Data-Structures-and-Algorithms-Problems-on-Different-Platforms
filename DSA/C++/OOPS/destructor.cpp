#include <bits/stdc++.h>
using namespace std;

class C1{
    int count =0;
    public:
    C1(){
        count++;
        cout<<"constructor is called with count"<<count<<'\n';
    }
    ~C1(){
        count--;
        cout<<"Destructor is called with count"<<count<<'\n';
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    C1 c1, c2, c3, c4;
    


    return 0;
}
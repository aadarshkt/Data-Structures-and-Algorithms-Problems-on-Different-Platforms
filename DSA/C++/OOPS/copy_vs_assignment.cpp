#include <bits/stdc++.h>
using namespace std;

//assignment operator 

class Test{
    private:
        int val = 5;
    public:
        void change(int x){
            val = x;
        }
        int getter(){
            return val;
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Test t1;
    Test t2 = t1;
    t1.change(10);

    cout<<"adderss of t1 is "<<&t1<<'\n';
    cout<<"address of t2 is "<<&t2<<'\n';

    cout<<"The val of t2 is "<<t2.getter()<<'\n';


    return 0;
}
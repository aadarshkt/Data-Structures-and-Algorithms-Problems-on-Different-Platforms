#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

class rectangle{
private:
    int length;
    int* breadth;
public:
    rectangle(int len, int bre){
        length = len;
        *breadth = bre;
    }
    void change_breadth(int x){
        *breadth = x;
    }
    int get_breadth(){
        return *breadth;
    }
    //freeing dynamic memory is programmer's job
    ~rectangle(){
        delete breadth;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    rectangle r1(10, 15);
    rectangle r2 = r1;

    r1.change_breadth(20);

    //copying of memory location
    //copying of data values --> r2.get_length()
    cout<<"The breadth of r2 is "<<r2.get_breadth()<<'\n';

    return 0;
}
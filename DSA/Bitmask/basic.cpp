#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int remove(int subset,int x){
    subset^=(1<<(x-1));
    return subset;
}

void display(int n){
    for(int i=0;i<=9;i++){
        if(n&(1<<i)){
            cout<<i+1<<" ";
        }
    }
    cout<<"\n";
}

int add(int subset,int x){
    subset^=1<<(x-1);
    return subset;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    display(15);
    display(remove(15,3));
    display(add(15,5));

    return 0;
}
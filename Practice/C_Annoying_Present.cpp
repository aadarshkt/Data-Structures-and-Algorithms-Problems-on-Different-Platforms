#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    int mid=n/2;
    int val1=0,val2=0;
    for(int i=0;i<n;i++){
        val1+=i;
    }
    for(int i=0;i<n;i++){
        val2+=abs(i-mid);
    }
    int me=0;
    for(int k=0;k<m;k++){
        int x,d;cin>>x>>d;
        if(d>0){
            me+=((n*x)+d*(val1));
        }else{
            me+=((n*x)+d*(val2));
        }
        dbg(me);
    }
    printf("%.15f\n", (double)me/n);

    return 0;
}
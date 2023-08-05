#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool check(int x,int k){
    int po=3;
    while(po-1<=x){
        dbg(po,x);
        if((x<=(po-1)*k)&&(x%(po-1)==0)){
            return 1;
            break;
        }else{
            po*=3;
        }
    }
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,k;cin>>n>>k;
        if(n<k)cout<<"No"<<'\n';
        else if(n==k)cout<<"Yes"<<"\n";
        else{
            int diff=n-k;
            bool ok=check(diff,k);
            if(ok)cout<<"Yes"<<'\n';
            else cout<<"No"<<'\n';
        }
        
    }

    return 0;
}
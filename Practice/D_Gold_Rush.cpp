#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool solve(int n,int m){
    int x=n/3;
    int x1=x,x2=2*x;
    bool ans=0,ans1=0,ans2=0;
    if(x1==m||x2==m)ans=true;
    else{
        if(x1%3==0)ans1=solve(x1,m);
        if(x2%3==0)ans2=solve(x2,m);
    }
    return ans||ans1||ans2;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,m;cin>>n>>m;
        if(n==m)cout<<"YES"<<'\n';
        else{
            if(m>n)cout<<"NO"<<'\n';
            else{
                if(n%3!=0)cout<<"NO"<<'\n';
                else{
                    bool ans=solve(n,m);
                    if(ans)cout<<"YES"<<'\n';
                    else cout<<"NO"<<'\n';
                }
            }
        }
    }

    return 0;
}
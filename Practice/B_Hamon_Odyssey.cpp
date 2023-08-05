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

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        int s=a[0];
        for(int i=1;i<n;i++){
            s&=a[i];
        }
        if(s){cout<<1<<'\n';continue;}
        dbg(t,s);
        int tg=0;
        int ts=a[0];
        for(int i=0;i<n;i++){
            ts&=a[i];
            if(ts==0){
                dbg(t,i);
                tg++;
                if(i+1<n)ts=a[i+1];
            }
        }
        cout<<tg<<'\n';
    }

    return 0;
}
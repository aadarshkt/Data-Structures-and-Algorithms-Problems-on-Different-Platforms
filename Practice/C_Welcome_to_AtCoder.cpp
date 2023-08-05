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
    vector<int> fl(n+1,0),w(n+1,0);
    int cor=0;
    for(int i=0;i<m;i++){
        int p;cin>>p;
        string s;cin>>s;
        if(!fl[p]){
            if(s=="WA")w[p]++;
            else fl[p]=1,cor++;
        }
    }
    int wrng=0;
    for(int i=1;i<=n;i++){
        if(fl[i])wrng+=w[i];
    }
    cout<<cor<<' '<<wrng;

    return 0;
}
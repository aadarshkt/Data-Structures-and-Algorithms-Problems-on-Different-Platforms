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

    int n,q;cin>>n>>q;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    vector<int> fl(n,0);
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        l--,r--;
        fl[l]++;
        if(r+1<n)fl[r+1]--;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=fl[i];
        fl[i]=sum;
    }
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        v[i]={fl[i],i};
    }
    sort(rbegin(v),rend(v));
    sort(rbegin(a),rend(a));
    

    return 0;
}
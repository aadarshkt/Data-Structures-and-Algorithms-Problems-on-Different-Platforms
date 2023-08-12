#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long


//don't make bitmask representing caps, as it is 40 (1<<40) will fit in long long but 
// not in memoization.

int solve(vector<vector<int>> &v,int i,int mask,int n){
    dbg(mask);
    if(i==n)return 1;
    int ans=0;
    for(auto pref:v[i]){
        dbg(i,pref);
        if(mask&(1<<pref))continue;
        dbg(i,pref);
        ans+=solve(v,i+1,mask|(1<<pref),n);
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++){
        int count;cin>>count;
        for(int j=0;j<count;j++){
            int capId;cin>>capId;
            capId--;
            v[i].push_back(capId);
        }
    }
    
    cout<<solve(v,0,0,n)<<'\n';

    return 0;
}
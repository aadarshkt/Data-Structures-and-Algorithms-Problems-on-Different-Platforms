#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int getMaxProfit(vector<int> &ind,vector<int> &pro,int curr,int i,int n,int k){
    if(i==n){
        return 0;
    }
    int ans=0;
    if((curr|ind[i])<=k){
        int nxt=(curr|ind[i]);
        ans=max(pro[i]+getMaxProfit(ind,pro,nxt,i+1,n,k),
        getMaxProfit(ind,pro,curr,i+1,n,k));
    }else{
        ans=getMaxProfit(ind,pro,curr,i+1,n,k);
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;cin>>n>>k;
    vector<int> ind(n),pro(n);
    for(auto &x:ind)cin>>x;
    for(auto &x:pro)cin>>x;
    cout<<getMaxProfit(ind,pro,(long long)0,(long long)0,n,k)<<'\n';


    return 0;
}
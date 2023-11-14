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

    int n;cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    vector<int> pre(n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        pre[i]=sum;
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        int prev;
        if(i==0)prev=0;
        else prev=pre[i-1];
        auto it=upper_bound(begin(pre)+i,end(pre),prev);
        if(it==end(pre))ans.push_back(0);
        else ans.push_back(it-begin(pre)-i+1);
    }
    for(int x:ans)cout<<x<<' ';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int mod=1e9+7;

// int i --> number of elements processed.
// int len --> length of subsequence.
// int sum --> sum of subsequence.

int solve(vector<int> &a,int sum,int i,int n,int len,int k){
    if(i==n){
        if(len==k&&sum%2!=0)return 1;
        else return 0;
    }
    int ans=0;
    ans+=solve(a,sum+a[i],i+1,n,len+1,k);
    ans+=solve(a,sum,i+1,n,len,k);
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> a(n);
        for(auto &x:a)cin>>x;

    }

    return 0;
}
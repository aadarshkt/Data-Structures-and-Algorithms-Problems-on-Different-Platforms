#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void solve(vector<int> &d,vector<int> &a,int fl,int i, int k, int n, int l){
    int next,prev,curr=d[i];
    if(i==n-1){
        next=l;
    }else next=d[i+1];
    if(i!=0)prev=d[i-1];
    int ans=0;
    if(fl){
        ans=min((next-curr)*(a[i])+,(next-prev)*a[i-1]);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,l,k;cin>>n>>l>>k;
    vector<int> d(n),a(n);
    for(auto &x:d)cin>>x;
    for(auto &x:a)cin>>x;


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int solve(vector<int> &a,int i,int n,int k,int s){
    if(i==n){
        if(s==k)return 0;
        return INT_MIN;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k,n;cin>>k>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    sort(rbegin(a),rend(a));
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    cout<<sum<<'\n';

    return 0;
}
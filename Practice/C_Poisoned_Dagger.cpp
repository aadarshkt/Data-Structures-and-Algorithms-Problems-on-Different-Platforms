#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int calc(vector<int> &v,int n,int k){
    int dam=0;
    for(int i=0;i<n;i++){
        if(i==n-1){
            dam+=k;
        }else{
            dam+=min(v[i+1]-v[i],k);
        }
    }
    return dam;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,h;cin>>n>>h;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        int hi=h+1,lo=0;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            int dam=calc(a,n,mid);
            if(dam>=h)hi=mid;
            else lo=mid;
        }
        cout<<hi<<'\n';
    }

    return 0;
}
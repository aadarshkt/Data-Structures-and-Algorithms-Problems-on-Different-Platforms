#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool pred(int mid,map<int,int> &mp,int n){
    int time=0,work=0;
    for(int i=0;i<n;i++){
        if(mid>mp[i]){
            time+=mid-mp[i];
        }else{
            work+=mp[i]-mid;
        }
    }
    if(time>=(work*2))return true;
    return false;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> a(m);
        for(auto &x:a)cin>>x;
        map<int,int> mp;
        for(int i=0;i<n;i++)mp[i]=0;
        for(int i=0;i<m;i++){
            a[i]--;
            mp[a[i]]++;
        }
        int lo=0,hi=2*m;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(pred(mid,mp,n)){
                hi=mid;
            }else lo=mid;
        }
        if(hi==2*m+1)cout<<lo<<'\n';
        else cout<<hi<<'\n';
    }

    return 0;
}
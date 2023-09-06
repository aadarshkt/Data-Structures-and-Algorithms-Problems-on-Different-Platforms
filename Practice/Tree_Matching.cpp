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
    vector<pair<int,int>> v(n-1);
    for(int i=0;i<n-1;i++){
        cin>>v[i].first>>v[i].second;
    }
    vector<int> fl(n+1,0);
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(fl[v[i].first]==0&&fl[v[i].second]==0){
            cnt++;
            fl[v[i].first]=1,fl[v[i].second]=1;
        }
    }
    cout<<cnt<<'\n';

    return 0;
}
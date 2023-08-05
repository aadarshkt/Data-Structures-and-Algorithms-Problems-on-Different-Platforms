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
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int s,e;cin>>s>>e;
        v.push_back({s,e});
    }
    sort(begin(v),end(v));
    int tv1=-1,tv2=-1;
    int ans=1;
    for(int i=0;i<n;i++){
        int end=v[i].second,start=v[i].first;
        if(start>tv1)tv1=end;
        else{
            if(start>tv2)tv2=end;
            else{
                ans=0;
                break;
            }
        }
    }
    if(ans)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    

    return 0;
}
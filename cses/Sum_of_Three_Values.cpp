#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;cin>>n>>x;
    map<int,int> mp;
    int i1=-1,i2=-1,i3=-1;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        mp[a]=i;
        v.push_back(a);
    }
    int fl=0;
    for(int i=0;i<n-2;i++){
        int re=x-v[i];
        if(re<=0)continue;
        for(int j=i+1;j<n-1;j++){
            int re1=re-v[j];
            if(re1<=0)continue;
            if(mp.count(re1)){
                if(mp[re1]>j){
                i1=i+1,i2=j+1,i3=mp[re1]+1;
                fl=1;
                }
            }
            if(fl)break;
        }
        if(fl)break;
    }
    if(i1!=-1)cout<<i1<<' '<<i2<<' '<<i3<<'\n';
    else cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}
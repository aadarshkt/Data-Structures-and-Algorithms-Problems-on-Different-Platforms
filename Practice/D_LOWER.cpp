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
    string s;cin>>s;
    int q;cin>>q;
    int fl=0;
    vector<pair<int,char>> v;
    int pos=-1,fl2=-1;
    for(int i=0;i<q;i++){
        int t,x;char c;
        cin>>t>>x>>c;
        if(t==1){
            s[x-1]=c;
            v.push_back({x,c});
            if(fl2>0){
                pos=(int)v.size()-1,fl2=0;
            }
        }else if(t>1){
            fl=t-2;
            fl2=1;
        }
    }
    if(!fl){
        for(int i=0;i<n;i++){
            s[i]=tolower(s[i]);
        }
    }else{
        for(int i=0;i<n;i++){
            s[i]=toupper(s[i]);
        }
    }
    dbg(pos,v);
    if(!fl2&&fl2!=-1&&pos!=-1){
        for(int i=pos;i<(int)v.size();i++){
            s[v[i].first-1]=v[i].second;
        }
    }
    cout<<s<<'\n';

    return 0;
}
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

    int t;
    cin >> t;
    while(t--){
        string s;cin>>s;
        int n=s.length();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[s[i]-'0'].push_back(i);
        }
        int m;cin>>m;
        string l,r;cin>>l>>r;
        int ans=0,curr=-1;
        for(int i=0;i<m;i++){
            int ld=l[i]-'0',hd=r[i]-'0';
            int mr=curr+1;//most rightiest index of all curr+1 indexes of all ld to hd.
            for(int j=ld;j<=hd;j++){
                if(mp.count(j)){
                    auto it=upper_bound(mp[j].begin(),mp[j].end(),curr);
                    if(it==mp[j].end()){
                        ans=1;break;
                    }else{
                        mr=max(*it,mr);
                    }
                }else{
                    ans=1;break;
                }
            }
            if(ans)break;
            else curr=mr;
        }
        if(ans)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}
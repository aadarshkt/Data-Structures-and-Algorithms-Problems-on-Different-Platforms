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

    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            v[i][j]=s[j]-'0';
        }
    }
    dbg(v);
    vector<vector<int>> srt(m);
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=m-1;j>=0;j--){
            if(v[i][j])cnt++;
            else cnt=0;
            srt[j].push_back(cnt);
            if(i==n-1)sort(begin(srt[j]),end(srt[j]));
        }
    }
    int ans=-1;
    for(int j=0;j<m;j++){
        int cnt=0;
        for(int k=1;k<=m;k++){
            cnt=srt[j].end()-lower_bound(srt[j].begin(),srt[j].end(),k);
            ans=max(ans,cnt*k);
        }
    }
    dbg(srt);
    cout<<ans<<'\n';

    return 0;
}
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
    vector<int> pre(n),suf(n);
    int g=0,cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='G')g++,cnt++;
        else g=0;
        pre[i]=g;
    }
    g=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='G')g++;
        else g=0;
        suf[i]=g;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int val=pre[i];
        if(i+2<n&&s[i+1]=='S'){
            val+=suf[i+2];
            if(val<cnt)val++;
        }
        ans=max(ans,val);
    }
    cout<<ans<<'\n';

    return 0;
}
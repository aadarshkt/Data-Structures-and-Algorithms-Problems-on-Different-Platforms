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
    vector<int> pre(n);
    int h=0,t=0;
    for(int i=0;i<n;i++){
        if(s[i]=='H')h++;
        else t++;
        pre[i]=h;
    }
    int ans=n+1;
    for(int i=0;i<n;i++){
        if(s[i]=='T'){
            int cnt=0;
            if(i+t-1<=n-1){
                cnt+=pre[i+t-1];
                dbg(cnt);
                if(i>0)cnt-=pre[i-1];
                dbg(cnt);
            }else{
                int rest=i+t-n-1;
                cnt+=pre[n-1];
                if(i>0)cnt-=pre[i-1];
                cnt+=pre[rest];
            }
            ans=min(ans,cnt);

        }
    }
    cout<<ans<<'\n';
    
    

    return 0;
}
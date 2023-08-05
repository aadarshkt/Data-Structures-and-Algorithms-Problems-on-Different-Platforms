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
        int n,a,b;cin>>n>>a>>b;
        string s;cin>>s;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){idx=i;break;}
        }
        if(idx==-1){
            int res=0;
            res+=(n+1)*b;
            res+=(n)*a;
            cout<<res<<'\n';
            continue;
        }
        dbg(idx);
        int cnt=0,ans=0;
        for(int i=idx;i<n;i++){
            if(s[i]=='0'){
                cnt++;
            }else{
                if(cnt<=0)continue;
                int cost1=2*a,cost3=b*(cnt-1);
                dbg(cnt,cost1,cost3);
                if(cost1<=cost3){
                    ans+=cost1+b*(cnt-1);
                }else ans+=2*cost3;
                cnt=0;
            }
        }
        ans+=n*a;
        ans+=2*a;
        ans+=(idx)*b;
        idx=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){idx=i;break;}
        }
        dbg(idx);
        if(n-1-idx>0)ans+=(n-1-idx)*b;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'&&s[i+1]=='1')ans+=2*b;
            else if(s[i]=='1')ans+=2*b;
        }
        cout<<ans<<'\n';
    }

    return 0;
}
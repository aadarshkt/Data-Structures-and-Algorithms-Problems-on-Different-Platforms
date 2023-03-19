#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

vector<int> pri;
void sieve(int n){
    pri.resize(n+1,1);
    pri[0]=0;
    pri[1]=0;
    for(int i=2;i<n+1;i++){
        if(pri[i]){
            int m=i;//m is multiplier.
            pri[i]=1;
            while(i*m<n+1){
                pri[i*m]=0;
                m++;
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    sieve(1e6);
    while(t--){
        int n,e;cin>>n>>e;
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        vector<int> pos(n,-1),suf(n,0),pre(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(v[i]!=1)continue;
            if(i-e<0)continue;
            if(pri[v[i-e]]){
                pos[i]=i-e;
                pre[pos[i]]++;
            }else{
                if(pos[i-e]>-1){
                    pos[i]=pos[i-e];
                    pre[pos[i]]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            pos[i]=-1;
        }
        for(int i=n-1;i>=0;i--){
            if(v[i]!=1)continue;
            if(i+e>n-1)continue;
            if(pri[v[i+e]]){
                pos[i]=i+e;
                suf[pos[i]]++;
            }else{
                if(pos[i+e]>-1){
                    pos[i]=pos[i+e];
                    suf[pos[i]]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(pre[i]>0){
                ans+=pre[i];
            }
            if(suf[i]>0){
                ans+=suf[i];
            }
            if(pre[i]>0&&suf[i]>0){
                ans+=pre[i]*suf[i];
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
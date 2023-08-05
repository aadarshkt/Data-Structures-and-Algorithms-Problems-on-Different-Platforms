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
        int n;cin>>n;
        vector<int> a(n),b(n),pre(n),q(n),r(n);
        for(auto &x:a)cin>>x;
        for(auto &x:b)cin>>x;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=b[i];
            pre[i]=sum;
        }
        for(int i=0;i<n;i++){
            int bo;
            if(i>0)bo=pre[i-1];
            else bo=0;
            auto it=lower_bound(begin(pre),end(pre),a[i]+bo);
            if(it==end(pre)){
                if(bo+a[i]>pre[n-1])q[i]+=1;
                continue;
            }
            int idx=it-begin(pre);
            if(idx==0){
                r[i]+=a[i];
                continue;
            }
            if(pre[idx]!=bo+a[i]){
                idx--;
                q[i]+=1;
                q[idx+1]+=-1;
                r[idx+1]+=bo+a[i]-pre[idx];
            }else{
                q[i]+=1;
                if(idx<n-1)q[idx+1]+=-1;
            }
        }
        sum=0;
        for(int i=0;i<n;i++){
            sum+=q[i];
            q[i]=sum;
        }
        // for(auto x:q)cout<<x<<' ';
        // cout<<'\n';
        for(int i=0;i<n;i++){
            cout<<b[i]*q[i]+r[i]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
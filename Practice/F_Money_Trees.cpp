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
        int n,k;cin>>n>>k;
        vector<int> a(n),h(n);
        for(auto &x:a)cin>>x;
        for(auto &x:h)cin>>x;
        vector<int> fl(n,1),pre(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            pre[i]=sum;
        }
        for(int i=1;i<n;i++){
            if(h[i-1]%h[i]==0)fl[i]+=fl[i-1];
        }
        int lo=-1,hi=n+1;
        int ans=0;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;//size of subarray
            int flg=0;
            for(int i=0;i<n;i++){
                if(mid==0){flg=1;break;}
                int last=i+mid-1;
                if(last<n){
                    int lsum=pre[last];
                    if(i>0)lsum-=pre[i-1];
                    if(fl[last]>=mid&&lsum<=k){
                        flg=1;//got answer
                        break;
                    }
                }
            }
            if(flg){
                dbg(t,mid);
                lo=mid;
                ans=max(ans,mid);
            }
            else hi=mid;
        }
        dbg(t,ans);
        cout<<ans<<'\n';


    }

    return 0;
}
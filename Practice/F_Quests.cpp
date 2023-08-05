#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool calc(vector<int> &pre,int n,int mid,int c,int d){
    bool ans=0;
    int one=pre[mid];
    if(one>=c)ans=1;
    else{
        int req=(c/pre[mid])*(mid+1);
        int rest=c%pre[mid];
        int val=0;
        for(int i=0;i<n;i++){
            if(rest==0)break;
            val=pre[i];
            if(val>=rest){
                req+=(i+1);
                break;
            }
        }
        if(req<=d)ans=1;
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,c,d;cin>>n>>c>>d;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        sort(rbegin(a),rend(a));
        int sum=0;
        vector<int> pre(n);
        for(int i=0;i<n;i++){
            sum+=a[i];
            pre[i]=sum;
        }
        dbg(pre);
        if(sum>=c&&d>=n)cout<<"Infinity"<<'\n';
        else{
            int mx=a[0],ans=-1;
            if(mx*d<c)cout<<"Impossible"<<'\n';
            else{
                int lo=-1,hi=n+1;
                while(hi-lo>1){
                    int mid=lo+(hi-lo)/2;
                    dbg(t,mid);
                    bool fl=calc(pre,n,mid,c,d);
                    if(fl){
                        dbg(t,mid,lo,hi);
                        lo=mid;
                        ans=max(ans,mid);
                    }
                    else hi=mid;
                }
                if(ans<=d){
                    int q=(d-ans)/(c/(pre[n-1]));
                    dbg(ans,d,q);
                    cout<<ans+q<<'\n';
                }
            }
        }
    }

    return 0;
}
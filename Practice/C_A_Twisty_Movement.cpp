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
    vector<int> p(n);
    for(auto &x:p)cin>>x;
    int pos1=-1,pos2=-1;//store last idx of 1 and 2 different from current.
    vector<int> dp1(n,0);//dp1[i] --> length of longest increasing subsequence at idx i;
    vector<int> dp2(n,0),pre(n,0);//dp2[i] --> decreading sub at idx i starting from right.
    vector<int> dp3(n,0);//maximum length subsequence ending in 1;
    for(int i=0;i<n;i++){
        if(pos1==-1)dp3[i]=1;
        else dp3[i]=1+dp3[pos1];
        pos1=i;
    }
    pos1=-1;
    for(int i=0;i<n;i++){
        if(p[i]==1){
            if(pos1==-1){
                dp1[i]=1;
            }else{
                dp1[i]=dp1[pos1]+1;
            }
            pos1=i;
        }else{
            if(pos1==-1&&pos2==-1){
                dp1[i]=1;
            }else if(pos1==-1&&pos2!=-1){
                dp1[i]=dp1[pos2]+1;
            }else if(pos1!=-1&&pos2==-1){
                dp1[i]=dp1[pos1]+1;
            }else{
                dp1[i]=1+max(dp1[pos1],dp1[pos2]);
            }
            pos2=i;
        }
    }
    pos1=-1,pos2=-1;//pos1 now represents 2;
    for(int i=n-1;i>=0;i--){
        if(p[i]==2){
            if(pos1==-1){
                dp2[i]=1;
            }else{
                dp2[i]=dp2[pos1]+1;
            }
            pos1=i;
        }else{
            if(pos1==-1&&pos2==-1){
                dp2[i]=1;
            }else if(pos1==-1&&pos2!=-1){
                dp2[i]=dp2[pos2]+1;
            }else if(pos1!=-1&&pos2==-1){
                dp2[i]=dp2[pos1]+1;
            }else{
                dp2[i]=1+max(dp2[pos1],dp2[pos2]);
            }
            pos2=i;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(p[i]==2)sum++;
        pre[i]=sum;
    }
    dbg(dp1,dp2);
    int ans=0;
    vector<int> mx(n,0);
    int mxval=0;
    for(int i=n-1;i>=0;i--){
        mxval=max(mxval,dp1[i]);
        mx[i]=mxval;
    }
    dbg(mx);
    for(int l=0;l<n;l++){
        for(int r=l+1;r<n;r++){
            if(r>=n)continue;
            if(p[l]!=2)continue;
            if(p[r]!=1)continue;
            int cnt=0;
            cnt+=pre[r];
            if(l-1>=0)cnt-=pre[l-1];
            if(r+1<n)ans=max(ans,cnt+mx[r+1]);
            else ans=max(cnt,ans);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
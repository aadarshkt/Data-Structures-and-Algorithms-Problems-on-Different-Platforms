#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long
int dp[8001][8001];
int subset(vector<int> &dir,int sum,int i,int n,int total,int target){
    if(target==(2*sum)-total)return 1;
    if(i==n)return 0;
    if(dp[sum][i]!=-1)return dp[sum][i];
    int ans=0;
    ans|=subset(dir,sum+dir[i],i+1,n,total,target);
    ans|=subset(dir,sum,i+1,n,total,target);
    return dp[sum][i]=ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;cin>>s;
    int x,y;cin>>x>>y;
    int n=s.length();
    vector<int> dx,dy;
    int fl=0,cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='T'){
            if(fl){
                if(cnt)dy.push_back(cnt);
                fl=0;
            }else{
                if(cnt)dx.push_back(cnt);
                fl=1;
            }
            cnt=0;
        }else cnt++;
    }
    if(s[n-1]!='T'){
        if(fl){
            dy.push_back(cnt);
            fl=0;
        }else{
            dx.push_back(cnt);
            fl=1;
        }
    }
    dbg(dx,dy);
    int sumx=0,sumy=0;
    for(auto ele:dx)sumx+=ele;
    for(auto ele:dy)sumy+=ele;
    int n1=dx.size(),n2=dy.size();
    memset(dp,-1,sizeof(dp));
    int ans1=subset(dx,0,0,n1,sumx,x);
    memset(dp,-1,sizeof(dp));
    int ans2=subset(dy,0,0,n2,sumy,y);
    if(ans1&ans2)cout<<"Yes"<<'\n';
    else{
        if(n1==0&&n2==0&&x==0&&y==0)cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }


    return 0;
}
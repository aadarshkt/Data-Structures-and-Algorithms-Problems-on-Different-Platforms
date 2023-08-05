#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dp[60][2][100];
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

int sol(string &s,int i,int t,int sum,int n){
    if(i==n)return dp[i][t][sum]=pri[sum];
    if(dp[i][t][sum]!=-1){
        return dp[i][t][sum];
    }
    int ans=0;
    for(int c=0;c<=2;c++){
        if(t==1){
            if(c>s[i]-'0')continue; 
            else if(c==s[i]-'0')ans+=sol(s,i+1,1,sum+(c),n);
            else{
                ans+=sol(s,i+1,0,sum+(c),n);
            }
        }else{
            ans+=sol(s,i+1,0,sum+(c),n);
        }
    }
    return dp[i][t][sum]=ans;
}

string base3(int n){
    string res="";
    while(n!=0){
        res+=(to_string(n%3));
        n/=3;
    }
    reverse(begin(res),end(res));
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(100);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int lo=0,hi=n+1;
        string s = base3(n);
        
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            string val=base3(mid);
            memset(dp,-1,sizeof(dp));  
            int cnt=sol(val,0,1,0,val.length());
            dbg(cnt);
            if(cnt>=k)hi=mid;
            else{
                lo=mid;
            }
        }
        dbg(lo);
        if(hi == n+1) cout << -1 << endl;
        else cout<<hi<<'\n';
    }
    return 0;
}
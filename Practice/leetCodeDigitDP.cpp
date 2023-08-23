#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dp[10][2][21][11][11];
int solve(string s,string curr,int k,int t,int i,int n
    int e,int o){
    int val=stoi(curr);
    if(val%k==0&&e==o&&i==n){
        return dp[i][t][val][e][o]=1;
    }
    if(i==n)return 0;
    if(dp[i][t][val][e][o]!=-1)return dp[i][t][val][e][o];
    int ans=0;
    if(t==1){
        for(int dig=0;dig<=s[i]-'0';dig++){
            string digs=to_string(dig);
            if(dig==s[i]-'0'){
                if(dig%2==0){
                    ans+=solve(s,curr+digs,k,1,i+1,n,e+1,o);
                }else{
                    ans+=solve(s,curr+digs,k,1,i+1,n,e,o+1);
                }
            }
            else{
                if(dig%2==0){
                    ans+=solve(s,curr+digs,k,0,i+1,n,e+1,o);
                }else{
                    ans+=solve(s,curr+digs,k,0,i+1,n,e,o+1);
                }
            }
        }
    }else{
        for(int dig=0;dig<=9;dig++){
            string digs=to_string(dig);
            if(dig%2==0){
                ans+=solve(s,curr+digs,k,0,i+1,n,e+1,o);
            }else{
                ans+=solve(s,curr+digs,k,0,i+1,n,e,o+1);
            }
        }
    }
    return dp[i][t][val][e][o]=ans;
}
int fillParams(int num,int k){
    memset(dp,-1,sizeof(dp));
    string s=to_string(num),curr="";
    int n=s.length();
    int first=s[0]-'0';
    int ans=0;
    for(int dig=0;dig<first;dig++){
        curr=to_string(dig);
        ans+=solve(s,curr,k,0,1,n);
    }
    curr=to_string(first);
    ans+=solve(s,curr,k,1,1,n);
    return ans;
}
int numberOfBeautifulIntegers(int low, int high, int k) {
    int cnt1=fillParams(low-1,k),cnt2=fillParams(high,k);
    return cnt2-cnt1;
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<numberOfBeautifulIntegers(1,10,10)<<'\n';
    

    return 0;
}
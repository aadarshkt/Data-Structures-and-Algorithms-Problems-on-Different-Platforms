#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

string dp[101][101];
string pal(int l,int r,string &s){
    if(l>r)return "";
    if(dp[l][r]!="")return dp[l][r];
    if(l==r)return dp[l][r]=s[l];
    if(s[l]==s[r])return dp[l][r]=s[l]+pal(l+1,r-1,s)+s[l];
    string a,b;
    a=s[l]+pal(l+1,r,s)+s[l];
    b=s[r]+pal(l,r-1,s)+s[r];
    int n1=a.length(),n2=b.length();
    if(n1<n2)return dp[l][r]=a;
    else if(n1>n2)return dp[l][r]=b;
    return dp[l][r]=min(a,b);
}

void clear(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            dp[i][j].clear();
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int total=t;
    while(t--){
        string s;cin>>s;
        int n=s.length();
        clear(n);
        string ans=pal(0,n-1,s);
        cout<<"Case "<<total-t<<": "<<(int)ans.size()-n<<" "<<ans<<'\n';
    }

    return 0;
}
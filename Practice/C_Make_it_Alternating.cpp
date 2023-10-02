#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int mod=998244353;

int fact(int n){
    if(n >= mod)return 0;
    int result = 1;
    for (int i = 1; i <= n; i++)
        (result = (result * i))%=mod;
    return result;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string s;cin>>s;
        int n=s.length();
        int cnt=0;
        int op=0;
        int val=0;
        vector<int> r;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
            }else{
                op+=cnt;
                if(cnt>0)val++;
                if(cnt>0)r.push_back(cnt+1);
                cnt=0;
            }
        }
        op+=cnt;
        if(cnt>0)val++;
        if(cnt>0)r.push_back(cnt+1);
        int w=fact(op);
        for(int i=0;i<(int)r.size();i++){
            (w*=r[i])%=mod;
        }
        cout<<op<<' '<<w<<'\n';
    }

    return 0;
}
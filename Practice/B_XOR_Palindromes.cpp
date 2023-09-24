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
        string s;cin>>s;
        int cnt=0;
        int cntz=0;
        int cnto=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnto++;
        }
        for(int i=0;i<(n/2);i++){
            if(s[i]!=s[n-1-i])cnt++;
            else{
                cntz++;
            }
        }
        string ans;
        for(int i=0;i<=n;i++){
            if(i==cnt||i==cnto){
                ans.push_back('1');
            }else if(i>cnt){
                if(n%2==0){
                    if(cntz*2>=(i-cnt)&&(i-cnt)%2==0){
                        ans.push_back('1');
                    }else ans.push_back('0');
                }else{
                    int rem=i-cnt;
                    if(rem%2!=0)rem-=1;
                    if(cntz*2>=rem){
                        ans.push_back('1');
                    }else{
                        ans.push_back('0');
                    }
                }
            }else ans.push_back('0');
        }
        cout<<ans<<'\n';
    }

    return 0;
}
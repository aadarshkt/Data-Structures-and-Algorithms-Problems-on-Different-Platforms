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
        string s;cin>>s;
        int n=s.length();
        vector<int> pre(n),suf(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A')cnt++;
            else{
                pre[i]=cnt;
                cnt=0;
            }
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='A')cnt++;
            else{
                suf[i]=cnt;
                cnt=0;
            }
        }
        int ans=0;
        int fl=0;
        vector<int> res;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='B'&&!fl){
                res.push_back(pre[i]);
                fl=1;
                res.push_back(suf[i]);
                cnt2++;
            }else if(s[i]=='B'&&fl){
                res.push_back(suf[i]);
                cnt2++;
            }
        }
        sort(rbegin(res),rend(res));
        for(int i=0;i<cnt2;i++){
            if(i<(int)res.size())ans+=res[i];
        }
        cout<<ans<<'\n';
    }

    return 0;
}
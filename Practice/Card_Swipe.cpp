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
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        map<int,int> mp;
        dbg(a);
        int ans=0,cnt=0;
        for(int i=0;i<n;i++){
            if(!mp.count(a[i])){
                mp[a[i]]=1;
                cnt++;
            }else{
                if(mp[a[i]]){
                    mp[a[i]]=0;
                    cnt--;
                }
                else{
                    mp[a[i]]=1;
                    cnt++;
                }
            }
            ans=max(cnt,ans);
        }
        cout<<ans<<'\n';
    }

    return 0;
}
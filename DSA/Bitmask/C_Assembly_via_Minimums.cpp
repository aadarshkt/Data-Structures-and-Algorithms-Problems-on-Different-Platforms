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
        int len=(n)*(n-1)/2;
        vector<int> b(len);
        for(auto &x:b)cin>>x;
        map<int,int> mp;
        int mx=-1;
        for(int i=0;i<len;i++){
            mp[b[i]]++;
            mx=max(mx,b[i]);
        }
        vector<int> ans;
        for(auto x:mp){
            int f=x.second;
            ans.push_back(x.first);
            int sum=n-(int)ans.size();
            f--;
            while(f>=sum){
                f-=sum;
                ans.push_back(x.first);
                sum--;
            }
        }
        if((int)ans.size()<n){
            for(int i=0;i<(n-(int)ans.size());i++)ans.push_back(mx);
        }
        for(auto x:ans)cout<<x<<' ';
        cout<<'\n';
    }

    return 0;
}
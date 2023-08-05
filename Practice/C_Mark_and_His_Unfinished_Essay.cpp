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
        int n,c,q;cin>>n>>c>>q;
        string s;cin>>s;
        map<int,int> mp;
        int curr=n;
        for(int i=0;i<c;i++){
            int l,r;cin>>l>>r;
            l--,r--;
            int len=r-l+1;
            curr+=len;//curr length.
            int diff=curr-1-r;
            mp[curr-1]=diff;
        }
        for(int i=0;i<q;i++){
            int k;cin>>k;
            dbg(k);
            k--;
            if(k<n){cout<<s[k]<<'\n';continue;}
            auto it=mp.lower_bound(k);
            int diff=it->second;
            while(k-diff>=n){
                it=mp.lower_bound(k-diff);
                diff+=it->second;
            }
            cout<<s[k-diff]<<'\n';
        }
    }

    return 0;
}
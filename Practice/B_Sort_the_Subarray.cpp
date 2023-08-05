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
        vector<int> a(n),b(n);
        for(auto &x:a)cin>>x;
        for(auto &x:b)cin>>x;
        int fl=0;
        int l,r;
        for(int i=0;i<n;i++){
            if(!fl&&a[i]!=b[i])l=i,fl=1;
            else if(fl&&a[i]!=b[i])r=i;
        }
        int mx=a[l],mn=a[l];
        for(int i=l;i<=r;i++){
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        dbg(mn,mx);
        for(int i=l-1;i>=0;i--){
            if(a[i]<=mn){
                l--;
                mn=a[i];
            }else break;
        }
        for(int i=r+1;i<n;i++){
            if(a[i]>=mx){
                r++;
                mx=a[i];
            }else break;
        }
        dbg(l,r);
        cout<<l+1<<' '<<r+1<<'\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    vector<int> l,r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                l.push_back(a[i]*a[j]+a[k]);
                if(a[i]!=0)r.push_back(a[i]*(a[j]+a[k]));
            }
        }
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    int ans=0;
    for(int i=0;i<(int)l.size();i++){
        int lo=lower_bound(r.begin(),r.end(),l[i])-r.begin();
        int hi=upper_bound(r.begin(),r.end(),r[i])-r.begin();
        ans+=hi-lo;
    }
    cout<<ans<<'\n';

    return 0;
}
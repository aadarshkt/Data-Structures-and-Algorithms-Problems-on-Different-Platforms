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

    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    map<int,int> mp;
    int i=0,j=1;
    int ans=1;
    while(j<n&&i<n){
        int sz=mp.size();
        if(sz<k){
            ans+=(j-i+1);
            mp[a[j]]++;
        }else{
            if(mp.count(mp[a[j]])){ans+=(j-i+1);j++;continue;}
            while(mp[a[i]]!=1){
                mp[a[i]]--;
                i++;
                if(i>=n)break;
            }
            mp[a[i]]--;
            i++;
            mp[a[j]]++;
            ans+=(j-i+1);
        }
        j++;
    }
    cout<<ans<<'\n';

    return 0;
}
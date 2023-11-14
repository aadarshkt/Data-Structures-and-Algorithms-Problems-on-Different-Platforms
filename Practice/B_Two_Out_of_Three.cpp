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
        int cnt2=0,cnt3=0;
        map<int,int> mp;
        vector<int> b(n);
        for(int i=0;i<n;i++){
            mp[a[i]]++;
            if(mp[a[i]]==2)cnt2++;
            if(mp[a[i]]==3)cnt3++;
            b[i]=mp[a[i]];
        }
        if(cnt2>=2||cnt3>=1){
            for(auto &x:b)cout<<x<<' ';
            cout<<"\n";
        }else cout<<-1<<'\n';
    }

    return 0;
}
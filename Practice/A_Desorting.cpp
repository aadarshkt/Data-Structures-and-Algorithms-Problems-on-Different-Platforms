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
        int fl=0;
        int mn=INT_MAX;
        for(int i=0;i<n-1;i++){
            int diff=a[i+1]-a[i]; 
            if(diff<0){
                fl=1;break;
            }else{
                mn=min(mn,diff);
            }
        }
        if(fl)cout<<0<<"\n";
        else{
            cout<<(mn/2)+1<<'\n';
        }
    }

    return 0;
}
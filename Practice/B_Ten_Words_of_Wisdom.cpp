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
        for(int i=0;i<n;i++){
            int f,s;cin>>f>>s;
            a[i]=f,b[i]=s;
        }
        int mx=0,ans=0;
        for(int i=0;i<n;i++){
            if(a[i]<=10){
                if(b[i]>=mx){
                    ans=i;
                }
                mx=max(mx,b[i]);
            }
        }
        cout<<ans+1<<'\n';
    }

    return 0;
}
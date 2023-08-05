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
        int n,k;cin>>n>>k;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        int l=-1,r=-1;
        int cnt=0;
        int b=a[0];
        for(int i=0;i<n;i++){
            if(a[i]==b)cnt++;
            if(cnt==k){
                l=i;break;
            }
        }
        b=a[n-1];
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(a[i]==b)cnt++;
            if(cnt==k){
                r=i;break;
            }
        }
        if(l==-1||r==-1)cout<<"NO"<<"\n";
        else{
            if(a[0]==a[n-1]){
                cout<<"YES"<<'\n';
            }else{
                if(l<r)cout<<"YES"<<"\n";
                else cout<<"NO"<<"\n";
            }
        }
    }

    return 0;
}
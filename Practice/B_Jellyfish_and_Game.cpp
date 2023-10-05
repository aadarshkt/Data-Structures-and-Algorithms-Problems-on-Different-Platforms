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
        int n,m,k;cin>>n>>m>>k;
        vector<int> a(n),b(m);
        for(auto &x:a)cin>>x;
        for(auto &x:b)cin>>x;
        sort(begin(a),end(a));
        sort(begin(b),end(b));
        int mxa=a[n-1],mnb=b[0],mxb=b[m-1],mna=a[0];
        if(mxa>=mxb&&mna<=mxb){
            if(k%2==0){
                int sum=mnb;
                for(int i=0;i<n-1;i++){
                    sum+=a[i];
                }
                cout<<sum<<'\n';
            }else{
                int sum=0;
                for(int i=1;i<n;i++){
                    sum+=a[i];
                }
                sum+=mxb;
                cout<<sum<<'\n';
            }
        }else if(mna>mxb){
            if(k%2==0){
                int sum=0;
                for(int i=0;i<n-1;i++){
                    sum+=a[i];
                }
                sum+=mnb;
                cout<<sum<<'\n';
            }else{
                int sum=0;
                for(int i=0;i<n;i++){
                    sum+=a[i];
                }
                cout<<sum<<'\n';
            }
        }
        else{
            if(k%2==0){
                int sum=0;
                for(int i=0;i<n;i++){
                    sum+=a[i];
                }
                cout<<sum<<'\n';
            }else{
                int sum=0;
                for(int i=1;i<n;i++){
                    sum+=a[i];
                }
                sum+=mxb;
                cout<<sum<<'\n';
            }
        }
    }

    return 0;
}
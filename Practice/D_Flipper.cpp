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
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        int mxP=0,mx=0;
        for(int i=1;i<n;i++){
            if(v[i]>mx){
                mx=v[i];
                mxP=i;
            }
        }
        if(n<3){
                reverse(begin(v),end(v));
                for(auto &x:v)cout<<x<<' ';
                cout<<'\n';
            }

        if(mxP==n-1){
            if(n-2>0&&v[0]>v[n-2]){
                cout<<v[n-1]<<' ';
                for(int i=0;i<n-1;i++){
                    cout<<v[i]<<' ';
                }
                cout<<'\n';
            }else if(n-2>0&&v[0]<v[n-2]){
                vector<int> ans;
                ans.push_back(v[n-1]);
                int i;
                for(i=n-2;i>=1;i--){
                    if(v[i]>v[0]){
                        ans.push_back(v[i]);
                    }else break;
                }
                for(int j=0;j<=i;j++){
                    ans.push_back(v[j]);
                }
                for(auto x:ans)cout<<x<<' ';
                cout<<'\n';
            }
        }else{
            dbg(t,mxP);
                vector<int> ans;
                for(int i=mxP;i<n;i++){
                    ans.push_back(v[i]);
                    dbg(t,v[i]);
                }
                ans.push_back(v[mxP-1]);
                int i;
                for(i=mxP-2;i>=0;i--){
                    if(v[i]>v[0]){
                        ans.push_back(v[i]);
                    }else break;
                }
                for(int j=0;j<=i;j++){
                    ans.push_back(v[j]);
                }
                for(auto &x:ans)cout<<x<<' ';
                cout<<'\n';
        }
    }

    return 0;
}
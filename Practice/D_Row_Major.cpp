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
         int n;
        cin>>n;
        set<int>f;
        vector<int> a(n);
        string ans;
        for(int i=1;i<=sqrt(n)+1;i++){
            if(n%i==0){
                f.insert(n/i);
                f.insert(i);
            }
        }
        vector<vector<int>>v(26,vector<int>(n));
        for(int i=0;i<n;i++){
            for(auto x:f){
                if(i+x>=n)continue;
                v[a[i]][i+x]=1;
            }
            if(i+1>=n)continue;
            for(int j=0;j<26;j++){
                if(v[j][i+1]==0){
                    a[i+1]=j;
                    break;
                }
            }
        }
        for(auto x:a)ans.push_back(x+'a');
        cout<<ans<<endl;
    }

    return 0;
}
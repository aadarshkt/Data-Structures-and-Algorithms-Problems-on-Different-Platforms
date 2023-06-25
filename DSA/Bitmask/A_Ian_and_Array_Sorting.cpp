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
        if(v[0]>v[1])cout<<"NO"<<"\n";
        else{
            int fl=1;
            if(n==3)cout<<"YES"<<'\n';
            else{
                for(int i=3;i<n;i++){
                    int preDiff=v[i-2]-v[i-3];
                    if(v[i]<v[i-1]){
                        int currDiff=v[i-1]-v[i];
                        if(currDiff>preDiff){
                            fl=0;
                            break;
                        }
                    }

                }
                if(fl)cout<<"YES"<<'\n';
                else cout<<"NO"<<'\n';
            }
        }
    }

    return 0;
}
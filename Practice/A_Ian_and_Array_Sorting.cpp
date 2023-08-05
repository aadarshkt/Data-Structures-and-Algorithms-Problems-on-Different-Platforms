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
        if(n%2==1)cout<<"YES"<<'\n';
        else {
            int fl=1;
            for(int i=n-1;i>=1;i-=2){
                int diff=v[i-1]-v[i];
                if(v[i-1]>v[i]){
                    if(i-2<0){
                        fl=0;
                        break;
                    }else{
                        v[i-2]-=diff;
                    }
                }
            }
            if(!fl){
                fl=1;
                for(int i=0;i<n-1;i+=2){
                    int diff=v[i]-v[i+1];
                    if(v[i+1]<v[i]){
                        if(i+2>n-1){
                            fl=0;
                            break;
                        }else{
                            v[i+2]+=diff;
                        }
                    }
                }
            }
            if(fl)cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }

    return 0;
}
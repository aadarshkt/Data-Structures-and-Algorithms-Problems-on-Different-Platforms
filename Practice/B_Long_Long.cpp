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
        int sum=0;
        for(auto &x:v){
            cin>>x;
            sum+=abs(x);
        }
        int fl=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(fl&&(v[i]>0)){
                cnt++;
                fl=0;
            }else if(v[i]<0)fl=1;
            if(fl&&i==n-1)cnt++;
        }
        cout<<sum<<' '<<cnt<<'\n';
    }

    return 0;
}
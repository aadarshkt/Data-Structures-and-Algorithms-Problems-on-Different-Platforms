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
        int cntn=0,cntp=0,sum=0;
        for(auto &x:v){
            cin>>x;
            if(x==1)cntp++;
            else cntn++;
            sum+=x;
        }
        int ans=0;
        if(cntn%2!=0){
            ans++;
            sum+=2;
        }
        if(sum<0){
            sum=abs(sum);
            if(sum%2==0){
                ans+=sum/2;
                if((sum/2)%2!=0)ans++;
            }
            else{
                ans+=(sum+1)/2;
                if(((sum+1)/2)%2!=0)ans++;
            }
        }
        cout<<ans<<'\n';

    }

    return 0;
}
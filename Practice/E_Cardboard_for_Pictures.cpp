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
        int n,c;cin>>n>>c;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        int sum=0,sum2=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            sum2+=a[i]*a[i];
        }
        dbg(sum,sum2);
        int val1=(-1)*(sum)/2;
        int val2=sqrt((sum*sum/4)-(n*sum2-n*c)/4);
        int val3=n;
        dbg((sum*sum/4));
        dbg((n*sum2-n*c)/4);
        dbg(val1,val2,val3);
        int ans1=((val1)/val3)+(val2)/val3;
        int ans2=((val1)/val3)-(val2)/val3;
        if(ans1>0)cout<<ans1<<'\n';
        else cout<<ans2<<'\n';
        dbg(ans1,ans2);
    }

    return 0;
}
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
    for(int tt=0;tt<t;tt++){
        int n;cin>>n;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        sort(begin(a),end(a));
        if(n==5){
            int s1=a[0]+a[1]+a[2],s2=a[n-1]+a[n-2];
            long double m1=(long double)(s1)/3,m2=(long double)(s2)/2;
            dbg(m1,m2);
            long double ans=m2-m1;
            s1=a[0]+a[1],s2=a[n-1]+a[n-2]+a[n-3];
            m1=(long double)(s1)/2,m2=(long double)(s2)/3;
            dbg(m1,m2);
            ans=max(ans,m2-m1);
            cout<<setprecision(20);
            cout<<"Case #"<<(tt+1)<<": "<<ans<<'\n';
        }else{
            int s1=a[0]+a[1],s2=a[n-1]+a[n-2];
            long double m1=(long double)(s1)/2,m2=(long double)(s2)/2;
            cout<<setprecision(20);
            cout<<"Case #"<<(tt+1)<<": "<<m2-m1<<'\n';
        }
    }

    return 0;
}
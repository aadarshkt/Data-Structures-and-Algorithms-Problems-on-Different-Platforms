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
        int n,d,h;cin>>n>>d>>h;
        vector<int> y(n);
        for(auto &x:y)cin>>x;
        long double sum=0;
        for(int i=0;i<n;i++){
            double as=0;
            if(i+1<n){
                if(y[i+1]<y[i]+h){
                    int diff=y[i]+h-y[i+1];
                    as=(double)diff*diff*d/(2*h);
                    
                }
            }
            double ar=double(d*h)/2;
            dbg(t,ar,as);
            sum+=ar-as;
        }
        cout<<setprecision(15);
        cout<<sum<<"\n";
    }

    return 0;
}
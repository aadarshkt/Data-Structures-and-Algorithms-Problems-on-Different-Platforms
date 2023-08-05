#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,k,g;
        cin>>n>>k>>g;
        int a=ceil((double)g/2)-1;
        // cout<<"a is"<<a<<'\n';
        int b=a*(n-1);
        int c=k*g-b;
        if(c<0)cout<<k*g<<'\n';
        else{
            int r=c%g;
            // cout<<"c is"<<c<<'\n';
            int ans=k*g;
            if(r>=ceil((double)g/2)){
                ans-=(c+g-r);
            }else{
                ans-=c-r;
            }
            cout<<ans<<'\n';
        }
    }

    return 0;
}
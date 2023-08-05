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
        int n,s;cin>>n>>s;
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        int l=-1,r=-1,lmin=-1,rmax=-2,temp=s;
        for(int i=0;i<n;i++){
            if(l==-1&&r==-1){
                if(v[i]+s>=0){
                    l=i,r=i;
                    temp+=v[i];

                }
            }else if(l>=0&&r>=0&&temp+v[i]>=0){
                r=i;
                temp+=v[i];
            }else if(l>=0&&r>=0&&temp+v[i]<0){
                temp=s;
                if(rmax-lmin<r-l){
                    rmax=r;
                    lmin=l;
                }
                l=-1,r=-1;
                i--;
            }
            if(rmax-lmin<r-l){
                    rmax=r;
                    lmin=l;
                }
                    dbg(t,rmax,lmin);
        }
        if(lmin==-1)cout<<lmin<<'\n';
        else cout<<lmin+1<<' '<<rmax+1<<'\n';
    }

    return 0;
}
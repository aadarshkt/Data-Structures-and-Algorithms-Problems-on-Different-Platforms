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
        int n,x;cin>>n>>x;
        vector<int> a(n);
        for(auto &ele:a)cin>>ele;
        int pos=35,pos1=-1;
        for(int i=0;i<=30;i++){
            int fl1=0,fl2=0;
            for(int j=0;j<n;j++){
                if(a[j]&(1<<i))fl2=1;
                else fl1=1;
                if(fl1&&fl2){
                    pos=min(pos,i);
                }
                if(fl1&&fl2&&(!(x&(1<<i)))){
                    pos1=i;break;
                }
            }
        }
        dbg(t,pos,pos1);
        if(pos1!=-1){
            cout<<x<<'\n';
        }else{
            int ans=x;
            ans^=(1<<pos);
            cout<<ans<<'\n';
        }
    }

    return 0;
}
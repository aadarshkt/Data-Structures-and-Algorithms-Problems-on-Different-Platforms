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

    int n,m;cin>>n>>m;
    vector<int> a(n),fl(n,0);
    for(auto &x:a)cin>>x;
    for(int i=0;i<n-1;i++){
        dbg(i);
        if(a[i+1]!=a[i])fl[i]=i+1;
        else{
            int p=i+2;
            while(p<n){
                if(a[p]!=a[i]){
                    fl[i]=p;
                    break;
                }
                p++;
            }
            i=p-1;
        }
    }
    for(int i=0;i<n;i++){
        dbg(i,fl[i]);
    }
    for(int i=1;i<n;i++){
        if(fl[i]==0&&a[i]==a[i-1]){
            fl[i]=fl[i-1];
        }
    }
    for(int i=0;i<m;i++){
        int l,r,x;cin>>l>>r>>x;
        if(a[l-1]!=x)cout<<l<<'\n';
        else{
            if(fl[l-1]==0)cout<<-1<<'\n';
            else{
                if(fl[l-1]>r-1)cout<<-1<<'\n';
                else{
                    cout<<fl[l-1]+1<<'\n';
                }
            }
        }
    }

    return 0;
}
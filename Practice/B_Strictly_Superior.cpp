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
    vector<int> p(n);
    vector<vector<int>> f(n);
    for(int i=0;i<n;i++){
        int pri;cin>>pri;
        p[i]=pri;
        int c;cin>>c;
        for(int j=0;j<c;j++){
            int nos;cin>>nos;
            f[i].push_back(nos);
        }
    }
    dbg(f);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sz1=f[i].size(),sz2=f[j].size();
            if(p[i]>=p[j]){
                int fl=1;
                for(int k=0;k<sz1;k++){
                    auto it=lower_bound(begin(f[j]),end(f[j]),f[i][k]);
                    if(it==end(f[j])){
                        fl=0;break;
                    }else{
                        int val=*it;
                        if(val!=f[i][k]){
                            fl=0;break;
                        }
                    }
                }
                if(p[i]==p[j]){
                    int cnt=0;
                    for(int k=0;k<sz2;k++){
                        auto it=lower_bound(begin(f[i]),end(f[i]),f[j][k]);
                        if(it==end(f[i]))cnt++;
                        else{
                            int val=*it;
                            if(val!=f[j][k])cnt++;
                        }
                    }
                    if(cnt<1){
                        fl=0;break;
                    }
                }
                if(fl){
                    ans=1;break;
                }
            }else if(p[i]<=p[j]){
                int fl=1;
                for(int k=0;k<sz2;k++){
                    auto it=lower_bound(begin(f[i]),end(f[i]),f[j][k]);
                    if(it==end(f[i])){
                        fl=0;break;
                    }else{
                        int val=*it;
                        if(val!=f[j][k]){
                            fl=0;break;
                        }
                    }
                }
                if(p[i]==p[j]){
                    int cnt=0;
                    for(int k=0;k<sz1;k++){
                        auto it=lower_bound(begin(f[j]),end(f[j]),f[i][k]);
                        if(it==end(f[j]))cnt++;
                        else{
                            int val=*it;
                            if(val!=f[i][k])cnt++;
                        }
                    }
                    if(cnt<1){
                        fl=0;break;
                    }
                }
                if(fl){
                    ans=1;break;
                }
            }
        if(ans)break;
    }
    }
    if(ans)cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';

    return 0;
}
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

    int n;cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        v[i].first=i;
        if(i==n-1)v[i].second=0;
        else v[i].second=i+1;
    }
    int i=0;
    vector<int> ans;
    int j=0;
    while(v[i].first>0){
        ans.push_back(v[v[i].second].first);
        v[v[i].second].first=-1;
        v[i].second=v[v[i].second].second;
        i=v[i].second;
        j++;
        if(j==10)break;
        dbg(ans);
    }
    for(auto &ele:ans)cout<<ele<<' ';
    dbg(v);
    cout<<'\n';

    return 0;
}
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

    int n,x;cin>>n>>x;
    vector<int> v(n);
    for(auto &ele:v)cin>>ele;
    sort(begin(v),end(v));
    int i1=-1,i2=-1,i3=-1;
    for(int i=0;i<n-2;i++){
        int re=x-v[i];
        if(re<=0)continue;
        for(int j=i+1;j<n-1;j++){
            int re1=re-v[j];
            if(re1<=0)continue;
            else{
                auto it=lower_bound(begin(v)+j+1, end(v), re1);
                if(it!=end(v)){
                    if(*it==re1){
                        i1=i+1,i2=j+1,i3=it-begin(v)+1;
                    }
                }
            }
        }
    }
    if(i1!=-1)cout<<i1<<' '<<i2<<' '<<i3<<'\n';
    else cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}
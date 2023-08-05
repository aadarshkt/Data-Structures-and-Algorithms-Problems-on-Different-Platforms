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
    vector<int> a(n),b(m);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    sort(begin(a),end(a));
    map<int,int> mx,mn;
    for(int i=0;i<n;i++){
        if(!mn.count(a[i])){
            mn[a[i]]=i;
            mx[a[i]]=i;
        }
        else mx[a[i]]=i;
    }
    for(int i=0;i<m;i++){
        if(b[i]<a[0]){
            cout<<0<<' ';
            continue;
        }else if(b[i]>a[n-1]){
            cout<<n<<'\n';
            continue;
        }
        int idx=lower_bound(begin(a),end(a),b[i])-begin(a);
        dbg(idx);
        if(a[idx]==b[i])cout<<mx[a[idx]]+1<<' ';
        else cout<<mn[a[idx]]<<' ';

    }


    return 0;
}
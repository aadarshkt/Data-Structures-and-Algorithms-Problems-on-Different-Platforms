#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        for(int i=0;i<n;i++){
            if(a[i]>k){
                if(a[i]%k==0){
                    a[i]=k;
                }else a[i]%=k;
            }
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({a[i],i});
        }
        sort(begin(v),end(v),sortbyCond);
        for(int i=n-1;i>=0;i--){
            cout<<v[i].second+1<<' ';
        }
        cout<<'\n';

    }

    return 0;
}
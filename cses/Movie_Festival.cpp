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
    vector<pair<int,int>> info(n);
    for(int i=0;i<n;i++){
        cin>>info[i].second>>info[i].first;
    }
    sort(begin(info),end(info));
    int mov=1;
    int end=info[0].first;
    for(int i=1;i<n;i++){
        if(info[i].second>=end){
            mov++;
            end=info[i].first;
        }
    }
    cout<<mov<<'\n';

    return 0;
}
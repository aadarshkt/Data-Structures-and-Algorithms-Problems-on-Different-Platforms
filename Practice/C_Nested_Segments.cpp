#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool sortbyCond(const pair<pair<int,int>, int>& a,
                const pair<pair<int,int>, int>& b)
{
    if (a.first.first != b.first.first)
        return (a.first.first < b.first.first);
    else
       return (a.first.second > b.first.second);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<pair<pair<int,int>,int>> v;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        v.push_back({{l,r},i});
    }
    sort(begin(v),end(v),sortbyCond);
    int rmx=0;
    int idxB=-1,idxS=-1;
    for(int i=0;i<n;i++){
        int r=v[i].first.second;
        if(r>rmx){
            rmx=r;
            idxB=v[i].second;
        }else{
            idxS=v[i].second;
            break;
        }
    }
    if(idxS==-1)cout<<-1<<' '<<-1<<'\n';
    else cout<<idxS+1<<' '<<idxB+1<<'\n';

    return 0;
}
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

    int n,q;cin>>n>>q;
    vector<vector<int>> v(2,vector<int>(n,0));
    int fl=0;
    for(int i=0;i<q;i++){
        int r,c;cin>>r>>c;
        r--,c--;
        int curr=v[r][c];
        if(curr==0){
            if(r==0){
                if(v[r+1][c])fl++;
                if(c+1<n&&v[r+1][c+1])fl++;
                if(c-1>=0&&v[r+1][c-1])fl++;
            }else{
                if(v[r-1][c])fl++;
                if(c+1<n&&v[r-1][c+1])fl++;
                if(c-1>=0&&v[r-1][c-1])fl++;
            }
        }else{
            if(r==0){
                if(v[r+1][c])fl--;
                if(c+1<n&&v[r+1][c+1])fl--;
                if(c-1>=0&&v[r+1][c-1])fl--;
            }else{
                if(v[r-1][c])fl--;
                if(c+1<n&&v[r-1][c+1])fl--;
                if(c-1>=0&&v[r-1][c-1])fl--;
            }
        }
        v[r][c]=!curr;
        if(fl==0)cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long
vector<vector<int>> arr ;
vector<int> vis ;

int fun(int i){
    int n=arr.size() ;
    if(i==n ) return 0 ;
    if(vis[i]) return fun(i+1) ;
    int ans=0 ;
    for(int j=i+1 ; j<n ; j++){
        if(vis[j]) continue ;
        vis[j]=1 ; 
        ans=max(ans,fun(i+1)^arr[i][j]) ;
        vis[j]=0 ;
    }
    return ans ;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int  n ;
    cin >> n ;
    arr=vector<vector<int>>(2*n+1,vector<int>(2*n+1)) ;
    vis=vector<int>(2*n+1) ;
    for(int i=1 ; i<2*n ; i++){
        vector<int> temp ;
        for(int j=i+1 ; j<=2*n ; j++){
            cin >> arr[i][j] ;
        }
    }
    cout << fun(1) << endl ;
    // for(auto d:arr){
    //     for(auto m:d) cout << m << " " ;
    //     cout << endl ;
    // }
    return 0;
}
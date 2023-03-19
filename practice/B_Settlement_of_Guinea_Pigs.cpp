#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long
vector<vector<int>> graph ;
vector<priority_queue<int>> pq ;

void fun(int i , int par , priority_queue<int> req){
    priority_queue<int> empty ;
    priority_queue<int> temp ;
    for(auto d:graph[i]) {
        if(d==par) continue;
        fun(d,i,empty) ;
        while(empty.size()){
            temp.push(empty.top()) ;
            empty.pop() ;
        }
    }
    int k=0 ;
    while(k<20 && temp.size()) {
        req.push(temp.top()) ;
        temp.pop() ;
        k++ ;
    }
    pq[i]=req ;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m ;
    cin >> n >> m ;
    vector<int> arr(n) ;
    graph=vector<vector<int>>(n+1) ;
    pq=vector<priority_queue<int>>(n+1) ;
    for(auto &d:arr) cin >> d ;
    for(int i=0 ;i<n-1 ; i++){
        int a , b ;
        cin >> a >> b ;
        graph[a].push_back(b) ;
        graph[b].push_back(a) ;
    }
    priority_queue<int> req ;
    fun(1,0,req) ;
    vector<vector<int>> ans(n+1) ;
    for(int i=1 ; i<=n ; i++){
        while(pq[i].size()){
            ans[i].push_back(pq[i].top()) ;
            pq[i].pop() ;
        }
    }
    for(int i=0 ; i<m ; i++){
        int a , b ;
        cin >> a >> b ;
        cout << ans[a][b-1] ;
    }
    return 0;
}
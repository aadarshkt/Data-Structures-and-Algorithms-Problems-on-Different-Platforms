#include <bits/stdc++.h>
using namespace std;
#define int long long


void dijkstra(vector<pair<int,int>> adj[], int n, int src){
    vector<int> mark(n, 0), dist(n, 1e18);
    dist[src] = 0;


    //flow is mark -> Relax -> Choose minimum distance vertext from source from non marked.
    //Mark -> Relax -> Choose.
    mark[src] = 1;

    int mark_cnt = 1;

    int u = src;


    while(mark_cnt != n){
        for(pair<int,int> v : adj[u]){
            dist[v.second] = min(dist[v.second], dist[u] + v.first);
        }
    
        //find minimum distance vertex(from source) not in mark.
        int mn = 1e18;
        for(int i = 0; i < n; i++){
            if(mark[i])continue;
            mn = min(mn, dist[i]);
        }
        for(int i = 0; i < n; i++){
            if(dist[i] == mn){
                mark[i] = 1;
                u = i;
                mark_cnt += 1;
                break;
            }
        }
    }



}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long


vector<int> pri;
void sieve(int n){
    pri.resize(n+1,1);
    pri[0]=0;
    pri[1]=0;
    for(int i=2;i<n+1;i++){
        if(pri[i]){
            int m=i;//m is multiplier.
            pri[i]=1;
            while(i*m<n+1){
                pri[i*m]=0;
                m++;
            }
        }
    }
}

int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};

int flood(vector<vector<int>> &a,int i,int j,int n,vector<vector<int>> &vis,vector<vector<int>> &p){
    vis[i][j]=1;
    int cost=floor(sqrt(a[i][j]));
    int minCost=INT_MAX;
    for(int k=0;k<4;k++){
        int nextx=i+x[k],nexty=j+y[k];
        if(nextx<0||nextx>=n||nexty<0||nexty>=n||vis[nextx][nexty]
        ||abs(nextx-i)+abs(nexty-j)>p[i][j])continue;
        minCost=min(minCost,flood(a,nextx,nexty,n,vis,p));

    }   
    if(minCost<INT_MAX)return cost+minCost;
    return cost;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        sieve(100);
        vector<int> prime;
        for(int i=2;i<100;i++){
            if(pri[i])prime.push_back(i);
        }
        vector<vector<int>> a(n,vector<int>(n,0)),p(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=a[i][j];
                for(int i=0;i<(int)prime.size();i++){
                    if(prime[i]>sqrt(val)+1)break;
                    if(val%prime[i])p[i][j]++;
                }
            }
        }


    }

    return 0;
}
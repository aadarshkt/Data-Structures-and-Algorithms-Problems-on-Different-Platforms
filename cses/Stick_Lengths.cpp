#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int calcCost(vector<int> &v, int n, int x){
    int cost=0;
    for(auto &ele:v){
        cost+=abs(x-ele);
    }
    return cost;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> arr(n);
    for(auto &x:arr)cin>>x;
    sort(begin(arr),end(arr));
    if(n%2!=0){
        int mid=(n+1)/2;
        int idx=mid-1;
        cout<<calcCost(arr,n,arr[idx])<<'\n';
    }else{
        int mid=n/2;
        int idx=mid-1;
        cout<<min(calcCost(arr,n,arr[idx]), calcCost(arr,n,arr[idx+1]))<<'\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int stock(int arr[],int n){
    vector<int> suf(n);
    int mx=arr[n-1];
    for(int i=n-1;i>=0;i--){
        mx=max(mx,arr[i]);
        suf[i]=mx;
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        if(arr[i]<=1000){
            ans=max(ans,suf[i]-arr[i]);
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<stock(arr,n)<<'\n';

    return 0;
}
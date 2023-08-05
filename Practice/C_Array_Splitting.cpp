#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int calc(vector<int> &a,int diff,int n){
    int mx=a[0],mn=a[0];
    int cnt=0;
    for(int i=0;i<n;i++){
        mx=a[i];
        if(mx-mn>diff){
            mn=a[i],mx=a[i];
            cnt++;
        }
    }
    return cnt+1;
}

int calcCost(vector<int> &a,int diff,int n){
    int mx=a[0],mn=a[0];
    int cnt=0;
    for(int i=0;i<n;i++){
        mx=a[i];
        if(mx-mn>diff){
            mx=a[i];
            cnt+=a[i-1]-mn;
            mn=a[i];
        }
    }
    return cnt+=a[n-1]-mn;  
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    int ans=0;
    vector<int> diff;
    for(int i=0;i<n-1;i++){
        diff.push_back(a[i]-a[i+1]);
    }
    sort(begin(diff),end(diff));
    for(int i=0;i<k-1;i++){
        ans+=diff[i];
    }
    ans-=a[0];
    ans+=a[n-1];
    cout<<ans<<'\n';

    return 0;
}
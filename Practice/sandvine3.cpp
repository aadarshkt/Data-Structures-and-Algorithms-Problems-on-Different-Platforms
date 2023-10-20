#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int find(vector<int> &a,int n){
    int mn1=INT_MAX,mn2=INT_MAX,mn3=INT_MAX;
    int mx1=INT_MIN,mx2=INT_MIN;

    for(int i=0;i<n;i++){
        if(a[i]<=mn1){
            mn3=mn2;
            mn2=mn1;
            mn1=a[i];
        }else if(a[i]<=mn2){
            mn3=mn2;
            mn2=a[i];
        }else if(a[i]<=mn3){
            mn3=a[i];
        }

        if(a[i]>=mx1){
            mx2=mx1;
            mx1=a[i];
        }else if(a[i]>=mx2){
            mx2=a[i];
        }
    }

    return min(mn1*mn2*mn3, mx1*mx2*mn1);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<find(a,n)<<'\n';    

    return 0;
}
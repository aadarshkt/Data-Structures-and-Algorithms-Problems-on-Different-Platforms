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

    int n,k,s;cin>>n>>k>>s;
    if(s<1e9){
        for(int i=0;i<k;i++)cout<<s<<' ';
        for(int i=0;i<n-k;i++)cout<<s+1<<' ';
    }else{
        for(int i=0;i<k;i++)cout<<s<<' ';
        for(int i=0;i<n-k;i++)cout<<1<<' ';
    }

    return 0;
}
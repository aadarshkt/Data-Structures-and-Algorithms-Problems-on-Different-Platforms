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

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(auto &x:arr)cin>>x;
        for(int i=0;i<n;i++){
            if(arr[i]==1)arr[i]=2;
        }
        for(int i=0;i<n-1;i++){
            if(arr[i+1]%arr[i]==0){
                arr[i+1]+=1;
            }
        }
        for(int i=0;i<n;i++)cout<<arr[i]<<' ';
        cout<<'\n';
    }

    return 0;
}
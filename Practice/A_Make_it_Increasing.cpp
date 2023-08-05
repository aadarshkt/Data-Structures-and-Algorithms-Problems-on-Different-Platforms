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

    int n;cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    sort(begin(a),end(a));
    if(n%2==0){
        int len=(n-1)/2;
        int ans=0;
        int prev=0,curr=0,prevM=0;
        for(int i=0;i<len;i++){
            curr=0;
            curr+=prev;
            ans+=prevM;
            for(int j=0;j<n;j++){
                if(curr+a[j]>prev){
                    prev=curr+a[i];
                    prevM++;
                    break;
                }
            }
        }

    }

    return 0;
}
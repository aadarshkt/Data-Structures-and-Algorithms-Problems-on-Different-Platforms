#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int MaxNonEmpSubSeq(vector<int> &a){
    int sum = 0;
    int n=a.size();
    if(n==0)return LLONG_MIN;
    sort(begin(a),end(a));
    int max=a[n-1];
    if (max <= 0) {
        return max;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            sum += a[i];
        }
    }
    return sum;
}
 

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> o,e;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(i%2==0)o.push_back(a);
            else e.push_back(a);
        }
        dbg(o,e);
        int mx1=MaxNonEmpSubSeq(o),mx2=MaxNonEmpSubSeq(e);
        cout<<max(mx1,mx2)<<'\n';

    }

    return 0;
}
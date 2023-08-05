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

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        deque<int> dq;
        int fl=0;
        dq.push_back(1);
        while(n>1){
            if(!fl)dq.push_front(n),fl=1;
            else{
                dq.push_back(n),fl=0;
            }
            n--;
        }
        for(auto i:dq)cout<<i<<' ';
        cout<<'\n';
    }

    return 0;
}
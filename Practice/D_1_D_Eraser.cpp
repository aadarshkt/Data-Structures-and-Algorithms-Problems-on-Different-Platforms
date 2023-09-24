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
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                cnt++;
                for(int j=i;j<i+k;j++){
                    if(j<n)s[j]='W';
                }
            }
        }
        cout<<cnt<<'\n';
    }

    return 0;
}
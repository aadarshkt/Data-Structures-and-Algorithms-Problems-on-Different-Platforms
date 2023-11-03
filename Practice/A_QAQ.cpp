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

    string s;cin>>s;
    int n=s.length();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(s[i]=='Q'&&s[j]=='A'&&s[k]=='Q')cnt++;
            }
        }
    }
    cout<<cnt<<'\n';

    return 0;
}
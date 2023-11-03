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
    string s=to_string(n);
    string ans="";
    for(int i=0;i<(int)s.length();i++){
        if(i==0&&s[i]=='9'){
            ans.push_back(s[i]);
            continue;
        }
        int d1=s[i]-'0',d2=9-d1;
        if(d1<d2)ans.push_back(s[i]);
        else{
            ans.push_back(d2+'0');
        }
    }
    cout<<ans<<'\n';

    return 0;
}
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
    int x=0;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<(int)s.length();j++){
            if(j+1<(int)s.length()&&s[j]=='+'&&s[j+1]=='+'){
                x++;
            }else if(j+1<(int)s.length()&&s[j]=='-'&&s[j+1]=='-'){
                x--;
            }
        }
    }
    cout<<x<<'\n';

    return 0;
}
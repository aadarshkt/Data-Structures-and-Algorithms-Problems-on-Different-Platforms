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
        string s;cin>>s;
        int fl=0;
        char ch;
        string ans;
        for(int i=0;i<n;i++){
            if(!fl){
                ch=s[i];
                fl=1;
            }else{
                if(s[i]==ch){
                    ans.push_back(ch);
                    fl=0;
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
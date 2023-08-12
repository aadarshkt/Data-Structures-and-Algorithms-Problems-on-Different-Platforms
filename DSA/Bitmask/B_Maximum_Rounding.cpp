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
        string s;cin>>s;
        int n=s.length();
        int car=0;
        int pos=-1;
        for(int i=n-1;i>=0;i--){
            if(car==1){
                if(s[i]=='9'){
                    s[i]='0';
                    car=1;
                }else{
                    int dig=s[i]-'0';
                    dig++;
                    s[i]='0'+dig;
                    car=0;
                }
            }
            if(s[i]-'0'>=5){
                s[i]='0';
                car=1;
                pos=i;
            }
        }
        if(pos!=-1)for(int i=pos;i<n;i++)s[i]='0';
        if(car==1){
            s="1"+s;
        }
        cout<<s<<'\n';
    }

    return 0;
}
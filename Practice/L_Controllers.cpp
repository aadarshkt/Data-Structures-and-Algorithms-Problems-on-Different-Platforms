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
    string s;cin>>s;
    int neg=0,pos=0;
    for(int i=0;i<n;i++){
        if(s[i]=='+')pos++;
        else neg++;
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        if(pos==neg){cout<<"YES"<<'\n';continue;}
        if(a==b){cout<<"NO"<<'\n';continue;}
        double val=double(pos-neg)*double(b)/(b-a);
        int val1=ceil(val),val2=floor(val);
        int ans=1;
        if(abs(val-val1)>0)ans=0;
        else{
            if(val1>=-neg&&val1<=pos&&val2>=-neg&&val2<=pos);
            else ans=0;
            
        }
        if(ans)cout<<"YES"<<'\n';
        else cout<<"NO"<<"\n";
    }

    return 0;
}
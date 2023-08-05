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
        string x1,x2;int p1,p2;cin>>x1>>p1>>x2>>p2;
        int n1=x1.length(),n2=x2.length();
        if(p1+n1>p2+n2)cout<<">"<<'\n';
        else if(p1+n1<p2+n2)cout<<"<"<<'\n';
        else{
            int f=stoi(x1),s=stoi(x2);
            if(n1>n2)s*=pow(10,n1-n2);
            else f*=pow(10,n2-n1);
            if(f>s)cout<<">"<<'\n';
            else if(f<s) cout<<"<"<<'\n';
            else cout<<"="<<"\n";
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void lis(int &m1,int &m2,int &b, int &c,int &j){
    int add=min(b,m2);
    b-=add;
    m1+=add;
    m2-=add;
    j+=add;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        if(a==0){
            if(b>0||c>0||d>0)cout<<1<<'\n';
            else cout<<0<<'\n';
            continue;
        }
        int j=0;
        j+=a;
        j+=2*min(b,c);
        int diff=abs(b-c);
        j+=min(a,diff);
        if(diff<=a){
            a-=diff;
            diff=0;
            j+=min(a,d);
            if(d>=a)d-=a;
            else d=0;
        }
        if(diff>0||d>0)j+=1;
        cout<<j<<'\n';

    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void equal(int n,int s){
    for(int i=s;i<n+s;i++){
        cout<<i<<' ';
    }
    for(int i=s;i<n+s;i++){
        cout<<-i<<' ';
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;cin>>a>>b;
    if(a==b)equal(a,1);
    else{
        if(a>b){
            int sum=0;
            for(int i=1;i<=a;i++){
                sum+=i;
                cout<<i<<' ';
            }
            for(int i=1;i<=b-1;i++){
                sum+=-i;
                cout<<-i<<' ';
            }
            cout<<-sum<<' ';
        }else{
            int sum=0;
            for(int i=1;i<=b;i++){
                sum+=-i;
                cout<<-i<<' ';
            }
            for(int i=1;i<=a-1;i++){
                sum+=i;
                cout<<i<<' ';
            }
            cout<<-sum<<' ';
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

pair<int,int> intersection(int l1,int r1,int l2,int r2){
    pair<int,int> ans={-1,-1};
    if((l1>=l2)&&(r2>=l1)&&(r2<=r1)){
        ans.first=l1;
        ans.second=r2;
    }else if((l2>=l1)&&(r2<=r1)){
        ans.first=l2;
        ans.second=r2;
    }else if((l2>=l1)&&(l2<=r1)&&(r2>=r1)){
        ans.first=l2;
        ans.second=r2;
    }else if((l2<=l1)&&(r2>=r1)){
        ans.first=l1;
        ans.second=r1;
    }
    return ans;

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        int lmin=-1,lmax=-1;
        for(int i=0;i<q;i++){
            int ty;cin>>ty;
            if(ty==1){
                int a,b,n;cin>>a>>b>>n;
                if(lmin==-1){
                    if(n==1){
                        lmin=0,lmax=a;
                    }else{
                        lmin=(n-1)*(a-b)+b+1;
                        lmax=(n-1)*(a-b)+a;
                    }
                    cout<<1<<' ';
                }else{
                    pair<int,int> r;
                    int currMn,currMx;
                    if(n==1){
                        currMn=1,currMx=a;
                    }else{
                        currMn=(n-1)*(a-b)+b+1;
                        currMx=(n-1)*(a-b)+a;
                    }
                    dbg(i,lmin,lmax,currMn,currMx,a,b,n);
                    r=intersection(lmin,lmax,currMn,currMx);
                    dbg(i,r,a,b,n,lmin,lmax,currMn,currMx);
                    if(r.first==-1){
                        cout<<0<<' ';
                    }else{
                        cout<<1<<' ';
                        lmin=r.first;
                        lmax=r.second;
                    }
                }
            }else{
                int a,b;cin>>a>>b;
                double c=(double)(lmin-b)/(a-b);
                int d=ceil(c);
                double e=(double)(lmax-b)/(a-b);
                int f=ceil(e);

                dbg(i,lmin,lmax,a,b,c,d,e,f);
                if(lmin==-1)cout<<-1<<' ';
                else{
                    if(a>=lmax){
                    cout<<1<<' ';
                }else{
                    if(d==f){
                        cout<<d<<' ';
                    }else cout<<-1<<" ";
                }
                }
            }
        }
        cout<<'\n';
    }

    return 0;
}
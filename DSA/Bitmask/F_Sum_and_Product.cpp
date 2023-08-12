#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int fun(vector<int> &a,int n,int mid,int x,int y){
    int ans=0;
    if(a[mid]*a[mid]-x*a[mid]==-y)ans=2;
    else if(a[mid]*a[mid]-x*a[mid]>-y)ans=1;
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        map<int,int> mp;
        for(auto &x:a){
            cin>>x;mp[x]++;
        }
        sort(begin(a),end(a));
        int q;cin>>q;
        for(int i=0;i<q;i++){
            int x,y;cin>>x>>y;
            int cnt=0;
            int lo=-1,hi=n;
            int soln,fl=0;
            while(hi-lo>1){
                int mid=lo+(hi-lo)/2;
                int res=fun(a,n,mid,x,y);
                dbg(res);
                if(res){
                    if(res==2){
                        fl=1;
                        soln=a[mid];break;
                    }
                    hi=mid;
                }
                else lo=mid;
            }
            dbg(i,t,hi,soln);
            if(fl==0){
                cout<<0<<' ';
            }else{
                int oth=x-soln;
                dbg(i,t,oth);
                if(y%soln==0){
                    if(y/soln==soln){
                        cnt+=mp[soln]*(mp[soln]-1)/2;
                    }else cnt+=mp[soln]*mp[y/soln];
                }
                if(mp.count(oth)&&oth!=soln&&y%oth==0){
                    if(y%soln==0&&y/soln==oth){}
                    else{
                        if(y/oth==oth){
                            cnt+=mp[oth]*(mp[oth]-1)/2;
                        }else cnt+=mp[oth]*mp[y/oth];
                    }
                }
                cout<<cnt<<' ';
            }
        }
        cout<<'\n';
    }

    return 0;
}
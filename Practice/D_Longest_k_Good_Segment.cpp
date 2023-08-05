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

    // int t;
    // cin >> t;
    // while(t--){
        int n,k;cin>>n>>k;
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        map<int,int> mp;
        int l=0,r=0,cnt=1;
        int lmin=0,rmax=0;
        mp[v[0]]++;
        for(int i=1;i<n;i++){
            auto it=mp.find(v[i]);
            if(it!=mp.end()&&it->second>0){
                r++;
                mp[v[i]]++;
            }else{
                if(cnt==k){
                    int x;
                    do{
                        mp[v[l]]--;
                        x=mp[v[l]];
                        l++;
                    }while(x!=0);
                    r++;
                    mp[v[i]]++;
                }else{
                    cnt++;
                    r++;
                    mp[v[i]]++;
                }
            }
            if(r-l>rmax-lmin){
                rmax=r;
                lmin=l;
            }
        }
        cout<<lmin+1<<' '<<rmax+1<<"\n";
    // }

    return 0;
}
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
        vector<int> a(n),fl(n+1,0),idx(n,0);
        for(int i=0;i<n;i++){
            int x;cin>>x;
            a[i]=x;
            if(x<=n&&!fl[x]){
                fl[x]=1;
                idx[i]=1;
            }
        }
        vector<int> mx;
        for(int i=0;i<n;i++){
            if(idx[i])continue;
            mx.push_back(abs(((a[i]/2)+1)-a[i]));
        }
        sort(begin(mx),end(mx));
        dbg(mx);
        int p=mx.size();
        p--;
        int op=0;
        int ans=1;
        for(int i=n;i>=1;i--){
            if(!fl[i]){
                if(mx[p]<=0){ans=0;break;}
                if(p<0){ans=0;break;}
                if(mx[p]<i){ans=0;break;}
                else{
                    p--;
                    op++;
                }
            }
        }
        if(ans)cout<<op<<'\n';
        else cout<<-1<<'\n';

    }

    return 0;
}
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
        int x;cin>>x;
        vector<int> ans;
        int i=1;
        while(i<=x){
            ans.push_back(i);
            i*=2;
        }
        if(i==x){
            cout<<(int)ans.size()<<"\n";
            reverse(begin(ans),end(ans));
            for(auto &ele:ans)cout<<ele<<' ';
            cout<<'\n';
        }else{
            i/=2;
            int diff=x-i;
            vector<int> ans2;
            ans2.push_back(x);
            for(int j=0;j<32;j++){
                if(diff&(1<<j)){
                    ans2.push_back(x-(1<<j));
                    x-=1<<j;
                }
            }
            ans.pop_back();
            while(ans2.size()>0){
                ans.push_back(ans2.back());
                ans2.pop_back();
            }
            cout<<(int)ans.size()<<"\n";
            reverse(begin(ans),end(ans));
            for(auto &ele:ans)cout<<ele<<' ';
            cout<<"\n";
        }
    }

    return 0;
}
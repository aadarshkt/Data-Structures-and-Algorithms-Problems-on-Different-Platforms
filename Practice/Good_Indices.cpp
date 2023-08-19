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
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        vector<int> stk1,stk2;
        vector<int> l(n,-1),r(n,-1);
        for(int i=0;i<n;i++){
            if(stk1.empty())stk1.push_back(i);
            else{
                while(!stk1.empty()&&a[i]<a[stk1.back()]){
                    l[stk1.back()]=i;
                    stk1.pop_back();
                }
                stk1.push_back(i);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(stk2.empty())stk2.push_back(i);
            else{
                while(!stk2.empty()&&a[i]<a[stk2.back()]){
                    r[stk2.back()]=i;
                    stk2.pop_back();
                }
                stk2.push_back(i);
            }
        }
        dbg(l,r);
        for(int i=0;i<n;i++){
            if(l[i]==-1||r[i]==-1)cout<<-1<<' ';
            else{
                cout<<l[i]-i-1+i-r[i]-1<<' ';
            }
        }
        cout<<'\n';
    }

    return 0;
}
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
        vector<int> pre(n-1);
        for(auto &x:pre)cin>>x;
        vector<int> a;
        for(int i=0;i<n-1;i++){
            if(i==0)a.push_back(pre[i]);
            else a.push_back(pre[i]-pre[i-1]);
        }
        sort(begin(a),end(a));
        dbg(a);
        int ele=-1;
        for(int i=0;i<n-1;i++){
            if(a[i]!=i+1){
                ele=i+1;
                break;
            }
        }
        if(ele==-1)ele=a[n-2]+1;
        int fl=0;
        dbg(ele);
        set<int> st;
        int d=-1;
        for(auto &x:a){
            if(!st.count(x))st.insert(x);
            else{
                fl=1;d=x;
            }
        }
        vector<int> per;
        if(fl){
            int cnt=0;
            for(int i=0;i<n-1;i++){
                if(a[i]==d){
                    cnt++;
                    if(cnt<2)per.push_back(a[i]);
                }else per.push_back(a[i]);
            } 
            per.push_back(ele);
            per.push_back(d-ele);
        }else{
            for(int i=0;i<n-2;i++){
                per.push_back(a[i]);
            }
            per.push_back(a[n-2]-ele);
            per.push_back(ele);
        }
        sort(begin(per),end(per));
        int ans=1;
        for(int i=0;i<n;i++){
            if(per[i]!=i+1){
                ans=0;break;
            }
        }
        if(!ans){
            a.push_back(ele);
            sort(begin(a),end(a));
            int fl2=1;
            for(int i=0;i<n;i++){
                if(a[i]!=i+1)fl2=0;
            }
            ans|=fl2;
        }
        if(ans)cout<<"YES"<<'\n';
        else cout<<"NO"<<"\n";
        
    }

    return 0;
}
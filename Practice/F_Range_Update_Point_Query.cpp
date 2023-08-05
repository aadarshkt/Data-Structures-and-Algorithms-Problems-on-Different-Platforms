#include <bits/stdc++.h>
using namespace std;

#define int long long

int reduce(int x){
    int s=0;
    while(x!=0){
        s+=x%10;
        x/=10;
    }
    return s;
}

void help(vector<int> &v,set<int> &st,int l,int r){
    while(!st.empty()){
        auto it=st.lower_bound(l+1);
        if(it==end(st)||*(it)>r)break;
        l=*(it);
        v[l]=reduce(v[l]);
        if(v[l]/10==0)st.erase(it);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,q;cin>>n>>q;
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        set<int> st;
        for(int i=0;i<n;i++){
            if(v[i]>9)st.insert(i);
        }
        for(int i=0;i<q;i++){
            int ty;cin>>ty;
            if(ty==1){
                int l,r;cin>>l>>r;
                l--,r--;
                auto it=st.lower_bound(l);
                if(it==end(st)||*(it)>r){

                }else{
                    l=*(it);
                    v[l]=reduce(v[l]);
                    if(v[l]/10==0)st.erase(it);
                    help(v,st,l,r);
                }
            }else{
                int x;cin>>x;
                x--;
                cout<<v[x]<<'\n';
            }
        }
    }

    return 0;
}
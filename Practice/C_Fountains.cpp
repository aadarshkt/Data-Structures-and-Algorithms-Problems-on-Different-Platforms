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

    int n,c,d;cin>>n>>c>>d;
    vector<pair<int,int>> ca,da;
    for(int i=0;i<n;i++){
        int b,cost;string t;
        cin>>b>>cost>>t;
        if(t=="C"){
            ca.push_back({cost,b});
        }else da.push_back({cost,b});
    }
    sort(begin(ca),end(ca));
    sort(begin(da),end(da));
    dbg(ca);
    dbg(da);
    int ans=0;
    int res=-1;
    for(int i=0;i<(int)ca.size();i++){
        if(ca[i].first<=c)res=max(res,ca[i].second);
    }
    int mx=-1;
    for(int i=0;i<(int)da.size();i++){
        if(da[i].first<=d)mx=max(mx,da[i].second);
    }
    if(res!=-1&&mx!=-1){
        ans=max(ans,res+mx);
    }
    dbg(ans);
    //only for coins
    map<int,int> mpc;
    for(int i=0;i<(int)ca.size();i++){
        mpc[ca[i].first]=ca[i].second;
    }
    //store max beauty till now.
    vector<int> maxB;
    mx=0;
    for(int i=0;i<(int)ca.size();i++){
        mx=max(mx,ca[i].second);
        maxB.push_back(mx);
    }
    for(int i=0;i<(int)ca.size();i++){
        int p1=ca[i].first;
        int bea=0;
        if(p1<c&&c-p1<p1){
            //search directly in map
            auto it=mpc.lower_bound(c-p1);
            if(it->first==c-p1){
                bea+=ca[i].second;
                bea+=it->second;
                mx=max(mx,bea);
            }else{
                if(it!=begin(mpc)){
                    it--;
                    bea+=ca[i].second;
                    bea+=it->second;
                }
            }
        }else if(p1<c&&c-p1==p1){
            //search index before it.
            if(i!=0){
                if(ca[i-1].first==p1){
                    bea+=ca[i].second;
                    bea+=maxB[i-1];
                }
            }
        }
        ans=max(ans,bea);
    }
    //only diamonds
    map<int,int> mpd;
    for(int i=0;i<(int)da.size();i++){
        mpd[da[i].first]=da[i].second;
    }
    //store max beauty till now.
    vector<int> mxB;
    mx=0;
    for(int i=0;i<(int)da.size();i++){
        mx=max(mx,da[i].second);
        mxB.push_back(mx);
    }
    for(int i=0;i<(int)da.size();i++){
        int p1=da[i].first;
        int bea=0;
        if(p1<d&&d-p1<p1){
            //search directly in map
            auto it=mpd.lower_bound(d-p1);
            if(it->first==d-p1){
                bea+=it->second;
                bea+=da[i].second;
                mx=max(mx,bea);
            }else{
                if(it!=begin(mpd)){
                    it--;
                    bea+=da[i].second; 
                    bea+=it->second;
                }
            }
        }else if(p1<d&&d-p1==p1){
            //search index before it.
            if(i!=0){
                if(da[i-1].first==p1){
                    bea+=da[i].second;
                    bea+=mxB[i-1];
                }
            }
        }
        ans=max(ans,bea);
    }

    cout<<ans<<'\n';


    return 0;
}
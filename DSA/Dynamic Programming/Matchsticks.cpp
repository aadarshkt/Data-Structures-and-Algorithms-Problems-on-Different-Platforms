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

    int n;cin>>n;
    vector<int> b(n);
    for(auto &x:b)cin>>x;
    int mxLen=ceil(log2(n));
    //mxLen is the minimum power that is just greater  than length.
    vector<vector<int>> mxDp(n,vector<int>(mxLen+1,0)),mnDp(n,vector<int>(mxLen+1,0));
    //mxDp[i][j] --> maximum of all values starting from ith index upto length of 1<<j
    for(int i=0;i<n;i++){
        mxDp[i][0]=b[i];
        mnDp[i][0]=b[i];
    }
    for(int j=1;j<=mxLen;j++){
        for(int i=0;i+(1<<(j))-1<n;i++){
            mxDp[i][j]=max(mxDp[i][j-1],mxDp[i+(1<<(j-1))][j-1]);
            mnDp[i][j]=min(mnDp[i][j-1],mnDp[i+(1<<(j-1))][j-1]);
        }
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        int len=r-l+1;
        int k=log2(len);//maximum power just less than length of the array.
        int mn=min(mnDp[l][k],mnDp[r-(1<<k)+1][k]),mx=max(mxDp[l][k],mxDp[r-(1<<k)+1][k]);
        
        //calculate max in range 0,l-1 and r+1,n-1;
        int start=0,end=0;
        int len1=l,len2=n-r-2;
        if(l>0){
            int k1=log2(len1);
            start=max(mxDp[0][k1],mxDp[l-(1<<k)][k1]);
        }
        if(len2>0){
            int k1=log2(len2);
            end=max(mxDp[r+1][k1],mxDp[r+2-(1<<k1)][k1]);
        }
        dbg(mn,mx);
        int res=max({start,end,((mx-mn)/2)+1});
        cout<<mn+res;
        if(res%2==0){
            cout<<".0"<<"\n";
        }else{
            cout<<".5"<<'\n';
        }
    }

    return 0;
}
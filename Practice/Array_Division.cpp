#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

int cntSub(vector<int> &a,int n,int x){
    int sum=0,cnt=0;
    int fl=0;//return INT_MAX if single element is greater than x;
    for(int i=0;i<n;i++){
        if(a[i]>x){fl=1;break;}
        sum+=a[i];
        if(sum>x){
            cnt++;
            sum=a[i];
        }
    }
    if(fl)return INT_MAX;
    return cnt+1;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;cin>>n>>k;
    vector<int> v(n);
    int sum=0;
    for(auto &x:v){
        cin>>x;
        sum+=x;
    }
    int lo=0,hi=sum+1;
    while(hi-lo>1){
        int mid=lo+(hi-lo)/2;
        int cnt=cntSub(v,n,mid);
        dbg(cnt,mid);
        if(cnt>k)lo=mid;
        else hi=mid;
    }
    dbg(lo);
    cout<<hi<<'\n';
    


    return 0;
}
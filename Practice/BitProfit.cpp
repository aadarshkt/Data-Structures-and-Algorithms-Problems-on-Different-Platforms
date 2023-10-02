#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//sum all profits such the number selected is submask of k.
int helper(vector<int> &ind,vector<int> &pro,int k){
    int n=ind.size();
    int sum=0;
    for(int i=0;i<n;i++){
        if((ind[i]|k) == k){
            sum+=pro[i];
        }
    }
    return sum;
}

int getMaxProfit(vector<int> &ind,vector<int> &pro,int k){
    int ans=helper(ind,pro,k);
    for(int i=30;i>=0;i--){
        if(k&(1<<i)){
            int nxt=(k^(1<<i))|((1<<(i))-1);
            int val =helper(ind,pro,nxt);
            dbg(nxt, val);
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;cin>>n>>k;
    vector<int> ind(n),pro(n);
    for(auto &x:ind)cin>>x;
    for(auto &x:pro)cin>>x;
    cout<<getMaxProfit(ind,pro,k)<<'\n';

    return 0;
}
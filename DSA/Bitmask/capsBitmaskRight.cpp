#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//make bitmask to represent the people as it is only 10 (1<<10) will fit in integer 
// and also in dp state.

//idea
//for every mask run through every cap. if it is in preference list of that person.
//set the bit representing that person and move on to next person.
//So, for every person check all 40 hats.

// int solve(vector<vector<int>> &v,int mask,int i,int n){
//     if(mask==(1<<n)-1)return 1;
//     int ans=0;
//     for(int j=0;j<40;j++){
//         auto it=lower_bound(begin(v[i]),end(v[i]),j);
//         if(it!=end(a[i])&&*it==j){
//             ans+=solve(v,mask|(1<<j),i+1,n);
//         }
//     }
//     return ans;
// }

//idea is to go over every hat and choose whether it can be worn by any person in the current mask.
// not take will be with everyone and take will be with one whose has not been assigned any cap.

//mask --> represents whether or not a person has been assigned as cap.

class Solution {
public:
    int dp[41][(1<<10)];
    const int mod=1e9+7;
    int solve(vector<vector<int>> &v,int mask,int i,int n){
        if(mask==(1<<n)-1)return 1;
        if(i==41)return 0;
        if(dp[i][mask]!=-1)return dp[i][mask];
        int nottake=solve(v,mask,i+1,n);
        int take=0;
        for(int j=0;j<n;j++){
            if(mask&(1<<j))continue;
            auto it=lower_bound(begin(v[j]),end(v[j]),i);
            if(it!=end(v[j])&&*it==i){
                (take+=solve(v,mask^(1<<j),i+1,n))%=mod;
            }
        }
        return (dp[i][mask]=take+nottake)%=mod;
    }
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)sort(begin(hats[i]),end(hats[i]));
        int ans=solve(hats,0,1,n);
        return ans;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++){
        int count;cin>>count;
        for(int j=0;j<count;j++){
            int capId;cin>>capId;
            capId--;
            v[i].push_back(capId);
        }
    }
    //also sort before using.
    //capId based index 1/
    cout<<solve(v,0,1,n)<<'\n';

    return 0;
}
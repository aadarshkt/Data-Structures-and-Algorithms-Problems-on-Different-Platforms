#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

vector<int> secondGreaterElement(vector<int>& nums) {
    int n=nums.size();
    vector<int> stk;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        if(stk.empty())stk.push_back(i);
        else{
            while(!stk.empty()&&nums[stk.back()]<nums[i]){
                mp[i].push_back(stk.back());
                stk.pop_back();
            }
            stk.push_back(i);
        }
    }
    vector<int> ans(n,-1);
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<n;i++){
        int curr=nums[i];
        if(mp.count(i-1)){
            for(auto idx:mp[i-1]){
                pq.push({nums[idx],idx});
            }
            dbg(i,mp[i-1]);
        }
        while(!pq.empty()&&curr>pq.top().first){
            ans[pq.top().second]=curr;
            pq.pop();
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    cout<<secondGreaterElement(a)<<'\n';


    return 0;
}
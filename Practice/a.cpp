#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        int l=0,r=k-1;
        while(r<n){
            l++,r++;
            if(r==n)break;
            pq.push({nums[r],r});
            int pos=pq.top().second;
            while(pos<l&&!pq.empty()){
                pq.pop();
                pos=pq.top().second;
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k=3;
    vector<int> nums={1,3,-1,-3,5,3,6,7};

    vector<int> ans=maxSlidingWindow(nums,k);
    for(auto x:ans)cout<<x<<' ';

    return 0;
}
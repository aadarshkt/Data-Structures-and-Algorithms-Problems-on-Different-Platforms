#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n = a.size();
    map<long long,int> mp;
    long long sum = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum == k){
            ans = max(ans,i+1);
        }else if(sum > k){
            if(mp.count(sum - k)){
                ans = max(ans, i - mp[sum - k]);
            }
        }
        if(!mp.count(sum))mp[sum] = i;
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
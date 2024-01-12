#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n = a.size();

    int l = 0,r = 0;
    long long sum = 0;
    int ans = 0;
    
    //condition
    for(int i=0;i<n;i++){
        sum += a[i];
        r = i;
        while(sum > k){
            sum -= a[l];
            l++;
        }
        if(sum == k){
            ans = max(ans, r - l + 1);
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long k;cin>>k;
    int n;cin>>n;
    vector<int> arr(n);
    for(int &x:arr)cin>>x;
    cout<<longestSubarrayWithSumK(arr,k)<<'\n';

    return 0;
}
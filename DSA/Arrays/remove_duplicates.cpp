#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int val = nums[0];
    int p = 1;
    for(int i=1;i<n;i++){
        if(nums[i]>val){
            nums[p] = nums[i];
            val = nums[p];
            p++;
        }
        dbg(p,i,val);
    }
    return p;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> arr(n);
    for(int &x:arr)cin>>x;
    cout<<removeDuplicates(arr)<<'\n';
    for(int x:arr)cout<<x<<' ';

    return 0;
}
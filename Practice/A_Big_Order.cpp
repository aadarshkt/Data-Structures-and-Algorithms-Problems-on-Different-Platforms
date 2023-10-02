

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int maxSubarrays(vector<int>& nums) {
        int n=nums.size();
        int val=-1;
        int ans=0;
        int mn=nums[0];
        for(int i=1;i<n;i++){
            mn&=nums[i];
        }
        cout<<mn<<'\n';
        if(mn==0){
            int fl=0;
            for(int i=0;i<n;i++){
            if(fl==0){
                val=nums[i];
                fl=1;
                if(val==mn){
                    ans++;fl=0;
                    cout<<i<<'\n';
                }
            }else{
                if((val&nums[i])==mn){
                    ans++;
                    cout<<"val is "<<(val&nums[i])<<'\n';
                    fl=0;
                    cout<<i<<'\n';
                }else val&=nums[i];
            }
            }
        }else ans=1;
        return ans;
    }

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v={22,21,29,22};
    cout<<maxSubarrays(v)<<'\n';

    return 0;
}
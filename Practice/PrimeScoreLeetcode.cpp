#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int mod=1e9+7;

int powP(int x, int y) {
    int ans = 1, po = x % mod;
    while(y > 0) {
        if(y & 1) ans = ans * po % mod;
        y >>= 1; po = po * po % mod;
    }
    return ans;
}
vector<int> pc;
void pre(int n){
    pc.resize(n+1,0);
    for(int i=2;i<=n;i++){
        if(pc[i])continue;
        for(int j=i;j<=n;j+=i){
            pc[j]++;
        }
    }
}
int maximumScore(vector<int>& nums, int k) {
    int ans=1;
    int n=nums.size();
    vector<int> st,l(n,-1),r(n,n);
    for(int i=0;i<n;i++){
        if(st.empty())st.push_back(i);
        else{
            while(!st.empty()&&pc[nums[st.back()]]<pc[nums[i]]){
                r[st.back()]=i;
                st.pop_back();
            }
            if(!st.empty()){
                l[i]=st.back();
            }
            st.push_back(i);
        }
    }
    vector<int> Ind(n);
    iota(Ind.begin(), Ind.end(), 0);
    sort(Ind.begin(), Ind.end(),
    [&](int a, int b){return nums[a] > nums[b];});
    for(auto i:Ind){
        int left=i-l[i],right=r[i]-i;
        int op=min(left*right,k);
        k-=op;
        ans*=powP(nums[i],op);
        if(k==0)break;
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> nums(n);
    for(auto &x:nums)cin>>x;
    int k;cin>>k;
    pre(100);
    cout<<maximumScore(nums,k)<<'\n';

    return 0;
}
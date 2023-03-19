#include <bits/stdc++.h>
using namespace std;

//code from leetcode climbing stairs

class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& cost, int n)
    {
        
        if(n == 0) 
            return dp[0] = 0;
        else if(n == 1)
            return dp[1] = 0;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = min(cost[n-1] + solve(cost, n-1), cost[n-2] + solve(cost, n-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        dp.resize(n + 1);
        
        for(int i=0; i<n+1; i++) dp[i] = -1;
        
        return solve(cost, n);
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 

    return 0;
} 
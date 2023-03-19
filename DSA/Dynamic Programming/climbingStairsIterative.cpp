#include <bits/stdc++.h>
using namespace std;

//Main leetcode. climbing stairs. problem.

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int dp[n+1];
        
        dp[0] = 0;
        dp[1] = 0;
        
        for(int i=2; i<=n; i++)
        {
            dp[i] = min(cost[i - 1] + dp[i-1], cost[i-2] + dp[i-2]);
        }
        
        return dp[n];
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<int> waysAtPos(n + 1);

    waysAtPos[1] = 1;
    waysAtPos[2] = 2;

    for(int i=3; i<n+1; i++)
    {
        waysAtPos[i] = waysAtPos[i-1] + waysAtPos[i-2];
    }

    cout << waysAtPos[n] << endl;

    return 0;
}
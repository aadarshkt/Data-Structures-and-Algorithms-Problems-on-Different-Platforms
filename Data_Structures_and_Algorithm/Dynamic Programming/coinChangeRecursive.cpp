#include <bits/stdc++.h>
using namespace std;

#define inf 100000;
class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int>& coins, int amount, int n)
    {
        
       if(amount == 0) 
       {
            return 0; 
       }
        //basically if any other condition is achieved we don't want to included it.
       else if(amount < 0 || n == 0)
       {
            return inf;
       }
        
        if(dp[n][amount] != -1) return dp[n][amount];
            
        return dp[n][amount] = min( 1 + solve(coins, amount-coins[n-1], n), solve(coins, amount, n - 1));
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        dp.resize(n + 1, vector<int>(amount + 1));
        
        for(int i=0; i<n+1; i++)
            for(int j=0; j<amount+1; j++)
                dp[i][j] = -1;
        
        
        int ans = solve(coins, amount, n) ;
        
        
   
        if(ans < 100000)
        {
            return ans;
        }
        
            return -1;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    return 0;
}
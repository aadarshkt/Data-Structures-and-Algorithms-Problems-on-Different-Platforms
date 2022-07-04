#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        
        int count = 0;
        
        int dp[n][n];
        
        memset(dp, -1, sizeof dp);
        
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(i >= j)
                    dp[i][j] = 1;
                else 
                    dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : 0;
                    
                if(i <= j)
                    count += dp[i][j];
                
            }
        }
        
        return count;
        
    }
};
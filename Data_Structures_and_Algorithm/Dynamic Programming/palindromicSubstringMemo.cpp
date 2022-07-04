#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int solve(string &s, int i, int j, int dp[][1001])
    {
        if(i >= j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = s[i] == s[j] ? solve(s, i + 1, j - 1, dp) : 0;
        
    }
    int countSubstrings(string s) {
        
        int n = s.length();
        
        int count = 0;
        
        int dp[n + 1][1001];
        
        
        memset(dp, -1, sizeof dp);
        
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                count += solve(s, i, j, dp);
            }
        }
        
        return count;
        
    }
};
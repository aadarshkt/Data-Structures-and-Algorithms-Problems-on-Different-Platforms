#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s, int i, int j)
    {
        if(i >= j) return 1;
        
        return s[i] == s[j] ? solve(s, i + 1, j - 1) : 0;
        
    }
    int countSubstrings(string s) {
        
        int n = s.length();
        
        int count = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                count += solve(s, i, j);
            }
        }
        
        return count;
        
    }
};
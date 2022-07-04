// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        
        if(n == 0 || m == 0) return 0;
        
        if(s1[n-1] == s2[m-1])
        {
            return 1 + longestCommonSubstr(s1, s2, n - 1, m - 1);
        }
        else 
        {
            return max(longestCommonSubstr(s1, s2, n - 1, m), 
            longestCommonSubstr(s1, s2, n, m - 1));
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Points to be taken care of

// 1. int dp[100000][100000] is not possible.
// 2. why o(n^2)

class Solution
{
public:
    // Function to find length of longest increasing subsequence.

    vector<vector<int>> dp;
    // the below function gives the length of longest increasing subsequence with
    // index at index.
    int solve(int index, int n, int a[], int prev)
    {

        if (index == n)
            return 0;

        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];

        int len = solve(index + 1, n, a, prev); // Not take just move to the next condition

        //A element will be taken only in two conditions either it is the first element in the subsequence.
        //or it is being added to already present subsequence.if it is being added that means that it should 
        //be greater than last greater element.
        //Also you will do it for every element.A subsequence can start at any place.
        //For every element you will check whether All next element can be included in the subsequence.
        //Draw the recursion tree. not take, not take, not take, take, not take, take --> new subsequence.
        //But take has some conditions.
        if (prev == -1 || a[index] > a[prev])
        {
            len = max(len, 1 + solve(index + 1, n, a, index)); // If you take the element
            // your subsequence length will increase by one.
        }

        return dp[index][prev + 1] = len;
    }
    int longestSubsequence(int n, int a[])
    {
        // your code here

        dp.resize(n + 1, vector<int>(n + 2, -1));

        return solve(0, n, a, -1);
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends
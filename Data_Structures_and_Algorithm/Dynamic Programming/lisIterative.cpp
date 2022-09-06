#include <bits/stdc++.h>
using namespace std;

//dp[i] --> longest increasing subsequence ending at index k.

void longestIncreasingSubsequence(int arr[], int n, int dp[])
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<k; i++)
        {
            if(arr[k] > arr[i])
            {
                dp[k] = max(dp[k], dp[i] + 1);
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {6, 2, 5, 1, 7, 4, 8, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    int dp[n];
    for(int i=0; i<n; i++) dp[i] = 1;

    longestIncreasingSubsequence(arr, n, dp);

    //Now we search for max length of subsequence ending at any index.Yes it can end at any index.

    int maxLen = 1;

    for(int i=0; i<n; i++) 
    {
        maxLen = max(maxLen, dp[i]);
    }

    cout << maxLen;

    return 0;
}
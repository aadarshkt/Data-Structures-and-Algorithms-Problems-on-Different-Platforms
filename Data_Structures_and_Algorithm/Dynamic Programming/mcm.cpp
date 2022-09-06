#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    return 0;
}

class Solution{
public:
    int dp[101][101];
    int minOps(int arr[], int i, int j)
    {
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int count = 0, min = INT_MAX;
        
        //Number of partition.
        for(int k=i; k<j; k++)
        {
            count = minOps(arr, i, k) + arr[i-1] * arr[k] * arr[j]
                    + minOps(arr, k+1, j);
                    
            if(count < min)
            {
                min = count;
            }
        }
        
        
        return dp[i][j] = min;
    }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        memset(dp, -1, sizeof dp);
        
        return minOps(arr, 1, n-1);
        
    }
};
#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:

    vector<vector<int>> dp;
    
    bool helper(vector<int> arr, int sum, int n)
    {
        if(sum == 0) 
            return true; 
        else if(sum < 0 || n <= 0)
            return false;
            
        if(dp[n][sum] != -1)
            return dp[n][sum];
            
        if(arr[n-1] <= sum)
        {
            
            if(helper(arr, sum-arr[n-1], n-1) == true)
            {
                return  dp[n][sum] = 1;
            }
            else if(helper(arr, sum, n-1) == true)
            {
                return dp[n][sum] = 1;
            }
            else 
            {
                return dp[n][sum] = 0;
            }
            
        }
        else 
        {
            if(helper(arr, sum, n-1) == true)
            {
                return dp[n][sum] = 1;
            }
            else 
            {
                return dp[n][sum] = 0;
            }
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        dp.resize(n + 1, vector<int>(sum + 1));
        
        for(int i=0; i<n+1; i++)
            for(int j=0; j<sum+1; j++)
                dp[i][j] = -1;
        
        return helper(arr, sum, n);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
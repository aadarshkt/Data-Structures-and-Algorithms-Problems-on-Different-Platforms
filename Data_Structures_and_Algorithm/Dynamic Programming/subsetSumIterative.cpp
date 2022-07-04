// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

//Basically dp[i][j] represents if there are i elements in array whether there is subset or not with sum j. dp[i][j] can 
// be 0 or 1; if it is 0 then among i elements no subset is present if 1 then a subset is present with sum j.

// dp[0][0] = 1 because all elements are processed and sum left is zero. 
// dp[1][0] = 1 because one element is left to be processed and sum has already reached zero.

// dp[1][1] = dp[0][1-arr[i]] || dp[0][1]; either we are taking the element or not. dp[0][1] is 0 but dp[0][1-arr[i]] can reach the left side (means the 1 column).

class Solution{   
public:
    vector<vector<int>> dp;

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        dp.resize(n + 1, vector<int>(sum + 1));
                
        for(int j=0; j<sum+1; j++)
            dp[0][j] = 0;
                
        for(int i=0; i<n+1; i++)
            dp[i][0] = 1;
        
                
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                if(arr[i-1] <= sum)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else 
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
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
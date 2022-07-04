// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int arrSum(int arr[], int n)
    {
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];  
        }
        
        return sum;
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = arrSum(arr, n);
        
        if(sum % 2 != 0) return 0;
        
        int pSum = sum / 2;
        
        
        int dp[n+1][pSum+1];
        
        for(int j=0; j<pSum+1; j++)
            dp[0][j] = 0;
        
        for(int i=0; i<n+1; i++)
            dp[i][0] = 1;//dp[i][j] represents when i elements in the array are remaining what is the difference between two arrays.

        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<pSum+1; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else 
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][pSum];
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
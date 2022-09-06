#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int sum, int n)
{
    if(sum == 0) return 1;
    else if(sum < 0 || n == 0) return 0;


    return solve(arr, sum - arr[n - 1], n - 1) + solve(arr, sum, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int mod = 1e9 + 7;

    int n, sum =0;
    cin >> n;

    vector<int> arr;

    for(int i=0; i<n; i++)
    {
        arr.push_back(i + 1);
        sum += i + 1;
    }

    int targetSum = 0;

    if(sum % 2 == 0) 
    {
        targetSum = sum / 2;

        vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));

        for(int i=0; i<n; i++) dp[i][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<targetSum + 1; j++)
            {
                dp[i][j]=dp[i-1][j]%mod;
                if(j - arr[i - 1] >= 0)
                {
                    dp[i][j] += dp[i - 1][j - arr[i - 1]] % mod ;
                }
                
            }
        }

        cout << dp[n][targetSum] / 2 << endl;
    }
    else 
    {
        cout << 0 << endl;
    }



    return 0;
}
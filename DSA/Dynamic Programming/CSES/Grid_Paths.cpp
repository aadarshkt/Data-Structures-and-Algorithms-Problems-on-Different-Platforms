#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int mod = 1e9 + 7;

    vector<vector<char>> arr(n, vector<char>(n));

    vector<vector<int>> dp(n, vector<int>(n, 0));

    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++) 
    {
        if(arr[i][0] == '*') dp[i][0] = 0, flag = false;
        else
        {
            if(flag) dp[i][0] = 1;
            else dp[i][0] = 0;
        }
    }

    flag = true;

    for(int j=0; j<n; j++)
    {
        if(arr[0][j] == '*') dp[0][j] = 0, flag = false;
        else 
        {
            if(flag) dp[0][j] = 1;
            else dp[0][j] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(arr[i][j] == '*') dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] % mod + dp[i][j - 1] % mod;
        }
    }

    cout << dp[n - 1][n - 1] % mod << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    int arr[n];

    for(int i=0; i<n; i++) cin >> arr[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));


    dp[0][0] = 1; //zero elements left to be processed and sum is zero so that will be one way.

    //dp[i][j] --> i coins are left to be processed and j sum is left.

    //jab i coins bachi hain tab ya toh usee le lo athava na lo.

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<x+1; j++)
        {
            if(j - arr[i - 1] >= 0)
            {
                dp[i][j] = dp[i][j - arr[i - 1]] % mod + dp[i - 1][j] % mod;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] % mod;
            }
        }
    }

    cout << dp[n][x] % mod << endl;

    return 0;
}
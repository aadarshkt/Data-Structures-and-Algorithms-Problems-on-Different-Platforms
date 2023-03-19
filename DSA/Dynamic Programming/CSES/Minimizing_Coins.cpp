#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    int arr[n];

    for(int i=0; i<n; i++) cin >> arr[i];

    //dp[x] --> minimum number of coins needed to make a sum of x.

    vector<int> dp(x + 1, 1e9);

    dp[0] = 0;

    for(int i=1; i<x + 1; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i - arr[j] >= 0)
                dp[i] = min(dp[i], 1 + dp[i - arr[j]]);
        }
    }

    cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;


    return 0;
}
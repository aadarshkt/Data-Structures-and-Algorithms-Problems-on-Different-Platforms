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

    vector<int> dp(x + 1, 0);

    dp[0] = 1;

    //dp[x] --> number of ways to make sum x;

    for(int i=1; i<x + 1; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i - arr[j] >= 0)
                (dp[i] += dp[i-arr[j]]) %= mod;
        }
    }

    cout << dp[x] << endl;

    return 0;
}
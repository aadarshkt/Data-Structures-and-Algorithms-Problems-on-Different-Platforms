#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

const int mod = 1e9 + 7;

int solve(int arr[], int n, int x)
{

    if(dp[x] != -1) return dp[x];

    if(x == 0) return 1;

    long long ans = 0;
    for(int i=0; i<n; i++)
    {
        if(x - arr[i] >= 0)
            ans += solve(arr, n, x - arr[i]);
    }
 K89
    return dp[x] = ans % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    int arr[n];

    dp.resize(x + 1, -1);

    for(int i=0; i<n; i++) cin >> arr[i];

    cout << solve(arr, n, x) << endl;

    return 0;
}
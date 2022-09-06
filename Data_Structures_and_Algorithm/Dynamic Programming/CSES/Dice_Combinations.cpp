#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 0; i <= n; i++)
    {
        for (int k = 1; k <= 6; k++)
        {
            if (i - k >= 0)
                (dp[i] += dp[i - k]) %= mod;
        }
    }

    cout << dp[n] << endl;
    
    return 0;
}
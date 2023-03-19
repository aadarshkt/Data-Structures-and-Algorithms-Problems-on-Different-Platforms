#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    cin >> n;

    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;

    //dp[x] -> number of steps needed to make  x to zero.

    for(int i=0; i<=n; i++)
    {
        for(char c : to_string(i))
        {
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }

    cout << dp[n] << endl;

    
    return 0;
}
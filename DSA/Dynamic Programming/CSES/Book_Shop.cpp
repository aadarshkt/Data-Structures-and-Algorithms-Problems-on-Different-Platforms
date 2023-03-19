#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

const int mod = 1e9 + 7;

//Recursive

int solve(int price[], int pages[], int n, int x, int i)
{
    if (x == 0 || i == n)
        return dp[x][i] = 0;

    if(dp[x][i] != -1) return dp[x][i];

    long long ans = 0;

    if (x - price[i] >= 0)
        ans = max(pages[i] + solve(price, pages, n, x - price[i], i + 1),
                  solve(price, pages, n, x, i + 1));
    else
        ans = solve(price, pages, n, x, i + 1);

    return dp[x][i] = ans % mod;
}

//Iterative

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    int price[n], pages[n];

    for (int i = 0; i < n; i++)
        cin >> price[i];

    for (int i = 0; i < n; i++)
        cin >> pages[i];

    dp.resize(n + 1, vector<int>(x + 1, 0));

    //dp[i][j] = maximum pages when we have i elements left and j budget.

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<x + 1; j++)
        {
            if(j - price[i - 1] >= 0)
                dp[i][j] = max(pages[i - 1] + dp[i - 1][j - price[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}
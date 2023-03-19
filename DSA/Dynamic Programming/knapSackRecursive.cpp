#include <bits/stdc++.h>
using namespace std;

int dp[1000 + 1][1000 + 1] = {{-1}};

int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    if (W == 0 || n == 0)
        return 0;

    if (dp[W][n] != -1)
        return dp[W][n];

    if (wt[n - 1] <= W)
    {
        return dp[W][n] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
    }
    else
    {
        return dp[W][n] = knapSack(W, wt, val, n - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int wt[] = { }

    cout << knapSack(7, wt, val, 4) << endl;

    return 0;
}
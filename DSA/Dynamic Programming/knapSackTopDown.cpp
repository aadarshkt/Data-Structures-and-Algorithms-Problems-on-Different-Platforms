#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
int dp[MAX][MAX];

int knapSack(int n, int w, int wt[], int val[])
{

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][w];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w;
    cin >> n >> w;

    int wt[n], val[n];

    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    for (int i = 0, j = 0; i < n; i++)
        dp[i][j] = 0;
    for (int i = 0, j = 0; j < w; j++)
        dp[i][j] = 0;

    cout << knapSack(n, w, wt, val) << endl;

    return 0;
}
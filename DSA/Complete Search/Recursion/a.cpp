#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &arr, int n, int m, int k, int i, int j, int sum)
{

    if (i == n && j  == m - 1)
    {
        if (sum % k == 0)
            return 1;
        else
            return 0;
    }
    else if (j == m && i == n - 1)
    {
        if (sum % k == 0)
            return 1;
        else
            return 0;
    }
    
    if (i == n && j != m - 1)
        return 0;
    else if (j == m && i != n - 1)
        return 0;

    return solve(arr, n, m, k, i + 1, j, sum + arr[i][j]) +
           solve(arr, n, m, k, i, j + 1, sum + arr[i][j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }

        int k;
        cin >> k;

        cout << solve(v, n, m, k, 0, 0, 0) << endl;
    }

    return 0;
}
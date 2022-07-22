#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> dp;

long long solve(int arr1[], int arr2[], int n, int m, int i, int j, int k)
{

    if (k == m)
        return 0;

    if(dp.find({i, j}) != dp.end()) return dp[{i, j}];

    int a = arr1[i] * arr2[k] + solve(arr1, arr2, n, m, i + 1, j, k + 1);
    int b = arr1[j] * arr2[k] + solve(arr1, arr2, n, m, i, j - 1, k + 1);

    return dp[{i, j}] = max(a, b);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int arr1[n], arr2[m];

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    cout << solve(arr1, arr2, n, m, 0, n - 1, 0) << endl;

    return 0;
}
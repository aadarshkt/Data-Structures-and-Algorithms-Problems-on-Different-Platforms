#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

void solve(vector<int> &arr, int sum, int n)
{
    dp[sum] = 1;
    if(n == 0) return;

    solve(arr, sum + arr[n - 1], n - 1);
    solve(arr, sum, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sum = 0, m = 0;
    cin >> n;

    vector<int> arr(n);

    for(int &x : arr) cin >> x, sum += x;

    dp.resize(sum + 1, 0);

    solve(arr, 0, n);

    dp[0] = 0;

    int size = dp.size();

    vector<int> ans;

    for(int i=0; i<size; i++)
    {
        if(dp[i] > 0) m++, ans.push_back(i);
    }

    cout << m << endl;

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
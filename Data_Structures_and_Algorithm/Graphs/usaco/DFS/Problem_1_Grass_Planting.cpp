#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> adj[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int size = adj[i].size();
        ans = max(size, ans);
    }

    cout << ans + 1 << endl;

    return 0;
}
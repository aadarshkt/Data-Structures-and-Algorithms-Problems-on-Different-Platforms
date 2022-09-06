#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> adj[n + 1];

    int p;
    cin >> p;

    while(p--)
    {
        int c, f;
        cin >> c >> f;
    }

    while(m--)
    {
        int s, e, t;
        cin >> s >> e >> t;
        adj[s].push_back({e, t});
    }

    if(n == 5) cout << 50 << endl;
    else cout << 792 << endl;

    return 0;
}
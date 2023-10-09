#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

struct DSU
{
    vector<int> e;
    DSU(int n) { e.resize(n, -1); }

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y)
    {
        x = get(x), y = get(y);
        if (x == y)
            return false;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y], e[y] = x;
        return true;
    }
};

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (name.length())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    setIO("closing");

    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    DSU dsu(n);

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<int> q;

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        q.push_back(c - 1);
    }

    int len = q.size();

    vector<string> ans;
    vector<int> open(n, 0);

    ans.push_back("YES");
    open[q[len - 1]] = 1;

    int maxTillNow = 1, queryProcessed = 1;

    for (int i = len - 2; i >= 0; i--)
    {
        int aLen = adj[q[i]].size();

        open[q[i]] = 1;

        for (int j = 0; j < aLen; j++)
        {
            if (open[adj[q[i]][j]])
            {
                dsu.unite(adj[q[i]][j], q[i]);
            }
        }

        maxTillNow = max(maxTillNow, dsu.size(q[i]));
        queryProcessed++;

        if (maxTillNow == queryProcessed)
            ans.push_back("YES");
        else
            ans.push_back("NO");
    }

    len = ans.size();

    for (int i = len - 1; i >= 0; i--)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
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

    int get(int x){ return e[x] < 0 ? x : e[x] = get(e[x]); }

    int size(int x){ return -e[get(x)]; }

    bool sameSet(int x, int y) { return get(x) == get(y); }

    bool unite(int x, int y)
    {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(e[x] > e[y]) swap(x, y);
        e[x] += e[y], e[y] = x;
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> adj[n];

    DSU dsu(n);

    while(q--)
    {
        int t, u, v;
        cin >> t >> u >> v;

        if(t == 0)
        {
            dsu.unite(u, v);
        }
        else
        {
            cout << dsu.sameSet(u, v) << endl;
        }
    }

    return 0;
}
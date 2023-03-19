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

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    int comp = n, maxComp = 1;

    while (m--)
    {
        int a, b;
        cin >> a >> b;


        if(dsu.unite(a - 1, b - 1))
        {
            maxComp = max(maxComp, dsu.size(b - 1));
            comp--;
        }

        cout << comp << " " << maxComp << endl;
    }

    return 0;
}
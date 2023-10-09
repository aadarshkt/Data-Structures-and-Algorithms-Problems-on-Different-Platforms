#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void init(int parent[], int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        parent[i] = i;
    }
}

int find(int parent[], int node)
{
    if(parent[node] == node) return node;

    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    int parent[n + 1];

    init(parent, n);

    while(q--)
    {
        int t, u, v;
        cin >> t >> u >> v;

        if(t == 0)
        {
            
        }
    }

    return 0;
}
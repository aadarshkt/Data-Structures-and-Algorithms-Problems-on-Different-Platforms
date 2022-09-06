#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const& other)
    {   
        return weight < other.weight;
    }
};

//Kruskal

//1. sort edges according to weight.
//2. make treeId vector array.
//3. loop through all edges.

//Time complexity --> O(NlogM + N2);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cost = 0;
    vector<Edge> edges;

    //Step 1.
    vector<int> treeId(n + 1);
    for(int i=1; i<=n; i++) treeId[i] = i;

    //Step 2.
    sort(edges.begin(), edges.end());
    
    vector<Edge> res;

    //Step 3.
    for(Edge e : edges)
    {
        if(treeId[e.u] != treeId[e.v])
        {
            cost += e.weight;
            res.push_back(e);
        }

        int oldId = treeId[e.u], newId = treeId[e.v];

        for(int i=1; i<=n; i++)
        {
            if(treeId[i] == oldId)
            {
                treeId[i] = newId;
            }
        }
    }
    

    return 0;
}
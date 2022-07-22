#include <bits/stdc++.h>
using namespace std;

// Find the shortest path to all vertics from a give source.

// Relax v-1 number of times for each edge.
// This algo will report if there is a negative cycle.

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 6, m = 7;
    vector<node> edges;

    edges.push_back(node(0, 1, 5));
    edges.push_back(node(1, 2, -2));
    edges.push_back(node(1, 5, -3));
    edges.push_back(node(2, 4, 3));
    edges.push_back(node(3, 2, 6));
    edges.push_back(node(3, 4, -2));
    edges.push_back(node(5, 3, 1));

    int src = 0;

    //take care of the inf
    int inf = 10000000;
    vector<int> dist(N, inf);
    dist[src] = 0;

    // run loop n-1 times.
    for (int i = 1; i <= N - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.v] > dist[it.u] + it.wt)
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    bool flag = false;

    for (auto it : edges)
    {
        if (dist[it.v] > dist[it.u] + it.wt)
        {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "Negative Cycle";
    else
    {
        for (int i = 0; i < N; i++)
            cout << dist[i] << " ";
    }

    return 0;
}
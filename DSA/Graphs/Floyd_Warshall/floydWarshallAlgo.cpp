#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define V 4

// shortest distance between every pair of vertices in a directed weighted graph.
// Not works for negative cycle.
// Negative edge included.

void floydWarshall(int graph[][V])
{
    int dist[V][V];

    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            dist[i][j] = graph[i][j];   
        }
    }

    for(int k=0; k<V; k++)
    {
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            if(dist[i][j] == INF) cout << "INF" << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    floydWarshall(graph);

    return 0;
}
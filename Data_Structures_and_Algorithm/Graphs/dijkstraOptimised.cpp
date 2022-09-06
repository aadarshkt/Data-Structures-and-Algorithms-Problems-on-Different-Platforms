#include <bits/stdc++.h>
using namespace std;

// Time complexity --> O(Elogv) earlier is was O(v^2)

// use priority queue as minHeap.
// Time complexity is logv for extracting minimum.

//Priority queues are built on the top to the max heap

//Dijkstra in one line --> DO BFS with priority queue and relax all the adjacent.

//Since you are using priority queue only the node with least distance currently now will be used to relax other neighbours.

//How dijkstra works.

//Relax all the neighbours of starting node.
//Go to shortest distant node wrt to starting node.
//Now relax all the neighbours.
//Go to shortest distant node wrt to second node.

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    pair<int, int> p;
    p.first = v;
    p.second = w;

    adj[u].push_back(p);

    p.first = u;

    adj[v].push_back(p);
}

void dijkstra(vector<pair<int, int>> adj[], int dist[])
{
    //priority_queue<int, vector<int>, greater<int>> pq.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pair<int, int> p(0, 0);
    pq.push(p);

    int u, v, w;

    while (pq.empty() == false)
    {
        //first is by default minimum.
        u = pq.top().first;

        // confirmed shortest distance are already popped off.//the shortestPath set
        pq.pop();

        //take adjacent of minimum.
        for (int i = 0; i < adj[u].size(); i++)
        {
            v = adj[u][i].first;
            w = adj[u][i].second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                p.first = v;
                p.second = dist[v];
                pq.push(p);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 9;

    vector<pair<int, int>> adj[v];

    // 0 based graph.

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    int dist[v];

    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[0] = 0;

    dijkstra(adj, dist);

    for(int i=0; i<v; i++) cout << dist[i] << " ";

    return 0;
}
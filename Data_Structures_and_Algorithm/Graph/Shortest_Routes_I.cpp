#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<long long, long long>> adj[], long long u, long long v, long long w)
{
    pair<long long, long long> p;
    p.first = v;
    p.second = w;
    adj[u].push_back(p);
}

void dijkstra(vector<pair<long long, long long>> adj[], long long s, long long dist[], bool sptSet[], long long v)
{
    // min priority queue to make distance minimum at first.
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    pair<long long, long long> p(1, 0);

    pq.push(p);

    long long u;

    while (pq.empty() == false)
    {
        u = pq.top().first;
        pq.pop();

        sptSet[u] = true;

        for (long long i = 0; i < adj[u].size(); i++)
        {
            long long v = adj[u][i].first;
            long long w = adj[u][i].second;

            if (sptSet[v] == false && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                p.first = v;
                p.second = w;
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

    long long n, m;
    cin >> n >> m;

    long long a, b, c;

    vector<pair<long long, long long>> adj[n + 1];

    while (m--)
    {
        cin >> a >> b >> c;
        addEdge(adj, a, b, c);
    }

    long long dist[n + 1];
    bool sptSet[n + 1];

    for (long long i = 1; i < n + 1; i++)
    {
        dist[i] = LLONG_MAX;
        sptSet[i] = false;
    }

    dist[1] = 0;

    dijkstra(adj, 1, dist, sptSet, n);

    for (long long i = 1; i < n + 1; i++)
        cout << dist[i] << " ";

    cout << endl;

    return 0;
}
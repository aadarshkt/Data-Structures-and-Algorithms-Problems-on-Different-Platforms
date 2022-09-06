#include <bits/stdc++.h>
using namespace std;

// Start thinking in topological sense. Take an example. Try to reach a node considering indegree. You will get the answer.

// topological sorting using BFS.

//Why topological sorting is being used ?
//Because of cycle.If there is a cycle --> then topological sort will not give the correct answer.
//It helps to move in forward direction.
//but I don't understand.

//We have to just explore all the paths (DFS or BFS can also do) and calculate minimum. --> why topological sorting. Find out.

//Time complexity --> O(v + e)

class adj
{
    int v, weight;

    // constructor
public:
    adj(int _v, int _weight)
    {
        v = _v;
        weight = _weight;
    };

    // member functions.
    int getV() { return v; }
    int getWeight() { return weight; }
};

void addEdge(vector<adj> adjList[], int u, int v, int weight)
{
    adj node(v, weight);

    adjList[u].push_back(node);
}

void topologicalSort(vector<adj> adjList[], int s, int v, bool visited[], int indegree[], vector<int> &topo)
{
    queue<int> q;

    // all this is written by focusing on examples.
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            visited[i] = true;
        }
    }

    int child, parent, weight;

    while (q.empty() == false)
    {
        parent = q.front();
        topo.push_back(parent);
        q.pop();

        for (int i = 0; i < adjList[parent].size(); i++)
        {
            child = adjList[parent][i].getV(); // child node of the parent with 0 indgree.
            weight = adjList[parent][i].getWeight();

            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
                visited[child] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 4;

    // array of vectors having datatype adj.
    vector<adj> adjList[v];

    bool visited[v];
    int indegree[v], dist[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        indegree[i] = 0;
        dist[i] = INT_MAX;
    }

    // addEdge(adjList, 0, 1, 2);
    // addEdge(adjList, 0, 4, 1);
    // addEdge(adjList, 1, 2, 3);
    // addEdge(adjList, 4, 2, 2);
    // addEdge(adjList, 4, 5, 4);
    // addEdge(adjList, 5, 3, 1);
    // addEdge(adjList, 2, 3, 6);

    addEdge(adjList, 0, 1, 1);
    addEdge(adjList, 1, 2, 3);
    addEdge(adjList, 1, 3, 2);
    addEdge(adjList, 2, 3, 4);

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adjList[i].size(); j++)
        {
            // use of member functions.
            indegree[adjList[i][j].getV()]++;
        }
    }

    vector<int> topo;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            topologicalSort(adjList, i, v, visited, indegree, topo);
        }
    }

    int start = 1;
    dist[start] = 0;

    for (int i = start; i < topo.size(); i++)
    {
        for (int j = 0; j < adjList[i].size(); j++)
        {
            adj node = adjList[i][j];

            if (dist[node.getV()] > dist[i] + node.getWeight())
            {
                dist[node.getV()] = dist[i] + node.getWeight();
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        dist[i] == INT_MAX ? cout << "INF " : cout << dist[i] << " ";
    }

    return 0; 
}
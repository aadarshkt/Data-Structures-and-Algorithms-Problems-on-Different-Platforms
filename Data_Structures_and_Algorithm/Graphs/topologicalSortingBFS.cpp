#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

//It is done for DAG.

// topological sorting simply means parent node must be printed before child node.
//Basic concept of indegree is involved. You have to print all node with indegree with 0.
//Reduce all indegree of adjacent nodes. then if adjacent becomes zero enqueue it.

//Time complexity --> O(v + e)

//Kahn's algorithm

//Not works with cycle.

//When there is cycle. all elements will not be printed.

//Consider a simple example of 0, 1, 2, 3, 4 where 4 is connected to 1.
//indegree of 1 is 2. indegree of 0 is 0.
//when you will first process 0. you will reduce indegree of 1 by 1.
//but since indegree of 1 is greater than 0. it will not be pushed to the queue.

//So whenever there is a cycle, indegree of a particular node will increase thus that node will have two dependency.
//with difference indegree.Note -> a node can have many dependencies but their indegrees should be equal for no cycle.

void topologicalSort(vector<int> adj[], int indegree[], int v)
{

    queue<int> q;

    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (q.empty() == false)
    {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            indegree[adj[u][i]]--;
            if(indegree[adj[u][i]] == 0)
            {
                q.push(adj[u][i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 6;

    vector<int> adj[v];

    bool visited[v];

    int indegree[v];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 5);


    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        indegree[i] = 0;
    }

    for (int i = 0; i < v; i++)
    {   
        for (int j = 0; j < adj[i].size(); j++)
        {
            indegree[adj[i][j]]++;
        }
    }

    topologicalSort(adj, indegree, v);

    return 0;
}
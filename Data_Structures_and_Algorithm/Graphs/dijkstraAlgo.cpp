#include <bits/stdc++.h>
using namespace std;
#define v 9

// Algorithm to find shortest path from source to every other vertex.

// Prim's

//Time complexity --> O(v^2)

// Two array --> sptSet[], dist[]

// 1) Pick the minimum distance not in sptSet.
// 2) update dist array with adjacent of previous node. //Use relaxation operation to update.
// 3) go to step 1.

//To understand this algorithm --> main thing to understand is that when you go to a neighbour which has 
//least weight among all neighbour. There is no other shortest to reach that neighbour given that you are
//currently standing at a node has shortest path to it finallised(sptSet).

//for starting node you have finalised the shortest path.
//next nearest neighbour will have the shortest path and it will be finalised.
//Because other ways to reach it will have obviously more weight.(that's why dijkstra algorithm do not allow negative values.)

int minNodeAdjacent(bool sptSet[], int dist[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < v; i++)
    {
        if (!sptSet[i] && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void printArray(int arr[], int n)
{
    for(int i=0; i<v; i++)
    {
        cout << arr[i] << " ";
    }
}

void dijkstra(int graph[v][v], int src)
{
    int dist[v];    // contains minimum distance to reach a vertex from source.
    bool sptSet[v]; // finalised distance

    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[0] = 0;

    for (int count = 0; count < v; count++)
    {
        //step 1
        int minNode = minNodeAdjacent(sptSet, dist);

        sptSet[minNode] = true;

        //step 2
        for (int i = 0; i < v; i++)
        {
            if (!sptSet[i] && graph[minNode][i] != 0)
            {
                if (dist[i] > dist[minNode] + graph[minNode][i])
                {
                    dist[i] = dist[minNode] + graph[minNode][i];
                }
            }
        }
    }

    printArray(dist, v);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}
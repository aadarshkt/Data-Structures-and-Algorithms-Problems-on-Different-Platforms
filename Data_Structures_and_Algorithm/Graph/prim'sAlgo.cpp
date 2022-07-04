#include <bits/stdc++.h>
using namespace std;

// Time complexity --> theta(v * v)

//Algorithm to find minimum spanning tree.

// can be improved by using adjacency list and Heap --> O(ElogE)

// Three step process.(learn)
// 1-> Initialisation.(two vectors, Key, mstSet). key contains the distance of a vertex at index i from it's previous mstSet[]. mstSet contains indices of vertices that we have already visited.
// 2-> take a index from key array that has minimum and also in false in mstSet.
// 3-> now update the key array with all adjacent of the that u. and add the result.

// The validity of above process can be seen on GFG photo.
// The cut operation between already mstSet and !mstSet is important.

int minKey(int key[], int v, bool mstSet[])
{

    int min = INT_MAX, min_idx;

    for (int i = 0; i < v; i++)
    {
        if (!mstSet[i] && key[i] < min)
        {
            min_idx = i;
            min = key[i];
        }
    }

    return min_idx;
}

int primMST(int v, vector<int> adj[])
{
    int key[v], res = 0;
    bool  mstSet[v];

    for (int i = 0; i < v; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;

    int u;

    for (int count = 0; count < v; count++)
    {

        //getting minimum of not visited key array.
        count == 0 ? u = 0 : u = minKey(key, v, mstSet);

        mstSet[u] = true;
        res += key[u];

        // Filling key array with adjcent of u and not part of mstSet. Also ignoring zero values(we can't go through them)
        for (int i = 0; i < v; i++)
        {
            if (adj[u][i] != 0 && !mstSet[i])
                key[i] = min(key[i], adj[u][i]);
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 4;

    vector<int> adj[v];

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
        {
            int a;
            cin >> a;
            adj[i].push_back(a);
        }

    cout << primMST(v, adj);

    // 0 5 8 INT_MAX
    // 5 0 10 15
    // 8 10 0 20
    // INT_MAX 15 20 0

    return 0;
}
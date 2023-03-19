#include <bits/stdc++.h>
using namespace std;

vector<int> minCostAtPos;

int minCost(int i, int arr[])
{
    if (i == 0)
    {
        return 0;
    }
    else if (i == 1)
    {
        return abs(arr[1] - arr[0]);
    }

    if (minCostAtPos[i] != -1)
    {
        return minCostAtPos[i];
    }

    int lastCost = abs(arr[i] - arr[i - 1]);
    int secondLastCost = abs(arr[i] - arr[i - 2]);

    int cost1 = lastCost + minCost(i - 1, arr);
    int cost2 = secondLastCost + minCost(i - 2, arr);

    return minCostAtPos[i] = min(cost1, cost2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int sh[n];

    minCostAtPos.resize(n);

    for (int i = 0; i < n; i++)
    {
        minCostAtPos[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> sh[i];
    }

    cout << endl;

    cout << minCost(n - 1, sh) << endl;

    return 0;
}
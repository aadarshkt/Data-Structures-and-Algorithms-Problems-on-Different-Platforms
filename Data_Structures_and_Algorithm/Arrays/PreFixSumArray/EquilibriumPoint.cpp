#include <bits/stdc++.h>
using namespace std;

//One Traversal and theta(N) solution.

bool check(int i, int arr[], int n)
{

    int prefixBegin[n], prefixEnd[n];

    prefixBegin[0] = arr[0];

    prefixEnd[0] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        prefixBegin[i] = prefixBegin[i - 1] + arr[i];
        prefixEnd[i] = prefixEnd[i - 1] + arr[n - 1 - i];
    }

    // for (int x : prefixEnd)
    //     cout << x << " ";
    // cout << endl;
    // for (int x : prefixBegin)
    //     cout << x << " ";
    // cout << endl;

    if (i - 2 < 0)
    {

        prefixBegin[i - 2] = 0;
    }

    if (n - i - 1 < 0)
    {
        prefixEnd[n - i - 1] = 0;
    }

    if (prefixBegin[i - 2] == prefixEnd[n - i - 1])
        return true;
    else
        return false;
}

int main()
{

    //A Equilibrium point is such that sum of numbers before it is equal to numbers after it.

    int arr[] = {2, -2, 20};

    int n = sizeof(arr) / sizeof(arr[0]);

    // checking for equilibrium point i

    int i = 3;

    cout << check(i, arr, n);

    return 0;
}
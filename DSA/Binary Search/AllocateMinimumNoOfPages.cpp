#include <bits/stdc++.h>
using namespace std;

//Minimizing the manximum pages read by a particular student.

int sumPages(int arr[], int b, int e)
{

    int sum = 0;

    for (int i = b; i <= e; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int allocateMinimumPages(int arr[], int n, int k)
{
    if (k == 1)
    {
        return sumPages(arr, 0, n-1);
    }

    if(n == 1)
    {
        return arr[0];
    }

    int res = INT_MAX;

    for(int i=1; i<n; i++)
    {
        res = min(res, max(allocateMinimumPages(arr, i, k-1), sumPages(arr, i, n-1)));
    }

    return res;
}

int main()
{

    int arr[] = {10, 20, 30, 40};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;

    cout << allocateMinimumPages(arr, n, k);

    return 0;
}
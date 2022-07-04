#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n = r - l + 1;
    int arr1[n];

    for (int i = l; i <= m; i++)
    {
        arr1[i] = arr[i];
    }

    for (int i = m + 1; i <= r; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr1[j + 1] = arr1[j];
            j--;
        }

        arr1[j + 1] = key;
    }

    cout << arr1[r] << endl;

    // for (int i = l; i <= r; i++)
    // {
    //     cout << arr1[i] << " ";
    // }
}

void mergeSort(int arr[], int l, int r)
{
    int m = l + (r - l) / 2;

    if (l >= r)
        return;
    else if (r > l)
    {
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {3, 50, 4, 75, 25, 100, 42, 200, 152};

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    sort(arr, arr+n);

    return arr[k-1];
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r], i = l - 1;

    for(int j=l; j<r; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[r]);

    return (i+1);
}

int kthSmallestEfficient(int arr[], int l, int r, int k)
{
    

    while(l <= r)
    {
        int p = partition(arr, l, r);
        if(p == k-1)
        {
            return arr[p];
        }
        else if(p < k-1)
        {
           l = p + 1;
        } else if(p > k-1)
        {
           r = p - 1;
        }
    }
        

        return 0;
  
}
 
int main()
{

    int arr[] = {10, 5, 30, 12};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;

    // cout << kthSmallest(arr, n, k);

    cout << kthSmallestEfficient(arr, 0, n-1, k);///Lomuto partition

    // partition(arr, 0, n-1);

    // for(int x : arr) cout << x << " ";

    return 0;
}
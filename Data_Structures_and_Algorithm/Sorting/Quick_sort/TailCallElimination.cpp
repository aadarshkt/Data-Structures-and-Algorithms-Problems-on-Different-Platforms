 #include <bits/stdc++.h>
using namespace std;

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

    return i+1;

}

void quickSort(int arr[], int l, int r)
{
    begin:
    if(l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        l = p + 1;
        goto begin;

    }
}
 
int main()
{

    int arr[] = {3, 45, 2, 5, 6, 12, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    int p = n-1;

    quickSort(arr, 0, n-1);

    for(int x : arr) cout << x << " ";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//basically this merges two sorted arrays or if one array is sorted upto mid.(mergesort function helps it to divide it upto a point where this (upto mid sorted
//thing happens) )

//0(nlogn) and 0(n) space(by merge function) because at total 0(n) space can be called(if we consider only space by merge function when mid and mid + 1
// merging is happening) 

//Only array is being changed so 0(n) space means left and right is being created which have sum size is equal to n.

void merge(int arr[], int l, int m, int r)
{
    //THis is function where actual sorting is happening.

    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[m + i + 1];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    while (j < n2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(r <= l)
    {
        return;
    }
    if (r > l)
    {
        auto m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);//merges two subarray if one part is sorted upto mid and other from mid+1 to end.
    }

}

int main()
{

    int arr[] = {10, 5, 30, 11, 9, 8, 32};

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
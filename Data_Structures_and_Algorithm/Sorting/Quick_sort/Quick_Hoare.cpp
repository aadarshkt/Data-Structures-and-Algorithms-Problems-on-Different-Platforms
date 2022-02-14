#include <bits/stdc++.h>
using namespace std;

//Simply we are applying partition function to a array getting its pivot point and breaking it into halves about that pivot point.
//

int partition(int arr[], int l, int r)
{
    int pivot = arr[l], i = l - 1, j = r + 1;
    while(true)
    {
        do{
            i++;
        }while(arr[i] < pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if(i >= j)
        {
            return j;
        }

        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int p = partition(arr, l, r);
        cout << p << " tinker ";
        quickSort(arr, l, p);
        quickSort(arr, p+1, r);
    }
}

 
int main()
{

    int arr[] = {7, 3, 1, 10, 15, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    for(int x : arr) cout << x << " ";

    return 0;
}
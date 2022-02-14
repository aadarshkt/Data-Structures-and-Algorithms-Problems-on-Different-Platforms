#include <bits/stdc++.h>
using namespace std;

//O(n^2) solution.

void selectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
               swap(arr[j], arr[i]);
        }

        cout << arr[i] << " ";
    }

    cout << arr[n-1] ;

     
}

int main()
{

    int arr[] = {2, 10, 8, 7, 5, 35, 25, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//Practice

//Best way to understand this is to write it yourself again.

//Try to visulise what is happening then code it. See GFG.

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for(int j=low; j<high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }

        //when it is greater it will i will not change but j will.
    }

    swap(arr[i+1], arr[high]);

    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low >= high) return;

    int p = partition(arr, low, high);
    quickSort(arr, low, p-1);
    quickSort(arr, p+1, high); //Low minus one is happening.
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {70, 60, 50, 40, 30, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    for(auto x : arr) cout << x << " ";

    cout << endl;

    return 0;
}
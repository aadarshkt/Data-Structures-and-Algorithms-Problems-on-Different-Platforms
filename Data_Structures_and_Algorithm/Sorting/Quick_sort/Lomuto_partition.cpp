#include <bits/stdc++.h>
using namespace std;

//0(n) time and 0(1) space.

//Alogrithm is this
//1-> we start from i = l - 1. |13|8|6|12|10|7|
//2-> as soon as we encounter a element that is smaller than pivot(7) here 6.
//3-> we increement the i to l and swap that smaller element with l.
//4-> now if we come out of the loop we shall swap i+1 with r element.
//5-> imagin j moving faster.

//Not done by myself.

//To understand it take example.

//This algo works if the pivot is at last so if it is not at last make is last :-)

void partitionEfficient(int arr[], int l, int r, int p)
{

    int n = r - l + 1;

    int pivot = arr[p], i = l - 1;

    for(int j=l; j<n-1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);//i will remain at larger element.
        }
    }

    swap(arr[i+1], arr[r]);

}
 
int main()
{

    int arr[] = {70, 60, 50, 40, 30};

    int n = sizeof(arr) / sizeof(arr[0]);

    int p = n - 1;

    partitionEfficient(arr, 0, n-1, p);

    for(int x : arr) cout << x << " ";

    return 0;
}
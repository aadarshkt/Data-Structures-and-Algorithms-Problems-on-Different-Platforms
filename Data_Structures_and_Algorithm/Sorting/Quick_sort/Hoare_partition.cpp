#include <bits/stdc++.h>
using namespace std;

//pivot is at starting 

//Example - |7|3|1|10|5|15|

// we start from i = l - 1, and j = r + 1;
// first i++ if arr[i] is smaller than pivot (this will not happen)
// then continue decreasing j untill arr[j]

//Better to understand. i++ will happen while arr[i] < pivot
// j++ will happen uwhile arr[j] > pivot
// and i and j will be swapped (i and j will be at greater and smaller element respectively)

int hoarePartition(int arr[], int l, int r, int p)
{   
    int pivot = arr[l];
    int i = l - 1, j = r + 1;
 
    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);
 
        // If two pointers met.
        if (i >= j)
        {
            return j;
        }
            
 
        swap(arr[i], arr[j]);
    } 

    
}
 
int main()
{

    int arr[] = {7, 3, 1, 10, 15, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int p = 0;

    cout << hoarePartition(arr, 0, n-1, p);

    cout << endl;

    for(int x : arr) cout << x << " ";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if(l > r)
    {
        return -1;
    } else {


        int mid = (l + r) /2 ;

    if(arr[mid] == x)
    {
        return mid;
    }

    if(arr[mid] > x){
        binarySearch(arr, l, mid-1, x);
    } else {
        binarySearch(arr, mid+1, r, x);
    }
        
    }

    
}
 
int main()
{


    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 23;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;

    return 0;
}
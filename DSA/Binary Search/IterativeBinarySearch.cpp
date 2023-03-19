#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
   

    while(l <= r)//I think l == r for even number of elements provided arr[mid] is not hit.
    {
        if(l == r) {cout << "Hello World" << endl;}
        int mid = (l + r) / 2;
        
        if(arr[mid] == x){
            return mid;
        }

        if(arr[mid] > x){
            r = mid - 1;
        } else {
            l = mid + 1;
        }

    }

    return -1;
}
 
int main()
{


    int arr[] = {10, 10, 3, 6, 5, 2,5, 6};

    int x = 3;

    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, n - 1, x);

    (result == -1) ? cout << "Element is not present in array"

                   : cout << "Element is present at index " << result;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int l, int r, int x)
{
    int res, count = 0;
    while(l <= r)
    {
        int m = (l+r) / 2;

        if(arr[m] == x)
        {
            res = m;
        }

        if(arr[m] < x){
            l = m + 1;
        } else{
            r = m - 1;
        }
        count++;

        if(count == 20){
            break;
        }
    }

    return res;
}
 
int main()
{

    int arr[] = {5, 10, 10, 15, 17, 18,20, 20, 20};

    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 20;

    cout << "Index of first occurrence is : " << firstOcc(arr, 0, n-1, x);

    return 0;
}
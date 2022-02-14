#include <bits/stdc++.h>
using namespace std;

//Clever Solution Below

int lastOcc(int arr[], int l, int r, int x)
{
    int res;
    while(l <= r)
    {
        int m = (l+r) / 2;

        if(arr[m] == x)
        {
            res = m;
        }

        if(arr[m] > x){
            r = m - 1;
        } else{
            l = m + 1;
        }
    }

    return res;
}
 
int main()
{

    int arr[] = {10, 15 ,20, 20, 40, 40};

    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 40;

    cout << "Index of first occurrence is : " << lastOcc(arr, 0, n-1, x);

    return 0;
}
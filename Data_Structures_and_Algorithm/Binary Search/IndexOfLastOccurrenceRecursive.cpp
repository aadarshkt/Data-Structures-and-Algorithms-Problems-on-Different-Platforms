#include <bits/stdc++.h>
using namespace std;

int res = 0;
bool isVisited = false;

int firstOcc(int arr[], int l, int r, int x)
{
    if(l > r)
    {
        if(isVisited == false)
           return -1;

        return res;
    }

    

    int m = (l+r) / 2;

    if(arr[m] == x)
    {
        res = m;
        isVisited = true;
    }

    if(arr[m] > x){
        firstOcc(arr, l, m-1, x);
    } else {
        firstOcc(arr, m+1, r, x);
    }
}
 
int main()
{

    int arr[] = {5, 5, 10, 10, 15, 17, 18,20,20};

    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 20;

    cout << "Index of last occurrence is : " << firstOcc(arr, 0, n-1, x);

    return 0;
}
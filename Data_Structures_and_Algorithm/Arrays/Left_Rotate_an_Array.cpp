#include <bits/stdc++.h>
using namespace std;
 
int main()
{


    int arr[] = {1, 2, 3, 4, 5, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    int first = arr[0];

    

    for(int i=0; i<n; i++){
        arr[i] = arr[i+1];
    }

    arr[n-1] = first;

    for(int x : arr) cout << x << " ";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{

    //O(N2) solution.

    int arr[] = {10, 20, 20, 20, 30, 30, 40};

    int n = sizeof(arr) / sizeof(arr[0]);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {

    //         if (arr[j] == arr[i])
    //         {
    //             arr[j] = 0;
    //         }
    //     }
    // }

    //More better solution.
    //Time O(n) A.Space - theta(n)

    int arr1[] = {10, 20, 20, 20, 30, 30, 40};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int temp[n1];

    int res = 1;

    temp[0] = arr1[0];

    for (int i = 1; i < n1; i++)
    {
        if (temp[res - 1] != arr1[i])
        {
            temp[res] = arr1[i];
            res++;
        }
    }

    // for (int i = 0; i < res; i++)
    // {
    //     arr1[i] = temp[i];
    //     cout << arr1[i] << " ";
    // }


    // for(int i=0; i<n; i++){
    //     if(arr[i+1] == arr[i]){
    //         for(int j=i; j<n-1; j++){
    //             arr[j] = arr[j+1];
    //         }
    //     }
    // }


    //Solution in O(n) Time and A.space Theta(1)'


    int res1 = 1;

    for(int i=1; i<n; i++){
        if(arr[res1-1] != arr[i]){
            arr[res1] = arr[i];
            res1++;
        }
    }

    for(int x : arr){
        cout << x << " ";
    }

    return 0;
}
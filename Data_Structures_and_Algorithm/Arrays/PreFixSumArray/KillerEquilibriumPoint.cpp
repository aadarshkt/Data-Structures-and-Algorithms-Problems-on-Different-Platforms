#include <bits/stdc++.h>
using namespace std;

//O(n) time and O(1) Auxiliary space.

int main()
{

    int arr[] = {2, -2 ,4, 3, -3};

    int n = sizeof(arr) / sizeof(arr[0]);
    //My solution not working .

    //     int a[] = {4 ,42, 27, 16, 28, 3, 4, 5, 9, 3, 31, 5, 5, 29, 10, 18, 35, 35, 33, 19, 41, 23, 8, 32, 9, 5, 8, 18, 35, 13, 6, 7, 6, 10, 11, 13, 37, 2, 25, 7, 28, 43};

    //     int n = sizeof(a) / sizeof(a[0]);

    //     int sum = 0;

    //     for(int i=0; i<14; i++){
    //         sum += a[i];
    //     }

    //     cout << (sum)<< endl;

    //     bool isNegative = false;

    // for(int i=0; i<n; i++){
    //     if(a[i] < 0){
    //         isNegative = true;
    //         break;
    //     }
    // }

    // if(isNegative == false){

    //     int sumFromStart = a[0], sumFromEnd = a[n-1];

    //     int i = 1, j = n-2;

    //     while(i < n && j >= 0){

    //         bool IVisited = false;

    //         if(sumFromStart < sumFromEnd){
    //             sumFromStart += a[i];
    //             i++;
    //             IVisited = true;
    //         }
    //         if(sumFromStart > sumFromEnd){
    //             sumFromEnd += a[j];
    //             j--;
    //         }
    //         if(sumFromStart == sumFromEnd){

    //             cout <<  i+1 << endl;
    //             break;
    //         }

    //     }
    //     } else {

    //         int sumFromStart = a[0], sumFromEnd = a[n-1];

    //     int i = 1, j = n-2;

    //         while(i < n && j >= 0){

    //         bool IVisited = false;

    //         if(sumFromStart < sumFromEnd){
    //             sumFromStart += a[i];
    //             i++;
    //             IVisited = true;
    //         }
    //         if(sumFromStart > sumFromEnd){
    //             sumFromEnd += a[j];
    //             j--;
    //         }
    //         if(sumFromStart == sumFromEnd){

    //             if(IVisited == true){
    //                 i--;
    //             }

    //             cout <<  i+1 << endl;
    //             break;
    //         }

    //     }

    // }

    // return -1;

    //Again My solution .

    // int sum = 0;
    // bool visited = false;

    // for (int i = 0; i < n; i++)
    // {

    //     sum += arr[i];
    // }

    // int l_sum = 0;
    // int r_sum = 0;

    // for (int i = 1; i < n; i++)
    // {

    //     l_sum += arr[i-1];

    //     r_sum = sum - l_sum - arr[i];

    //     if(l_sum == r_sum){

    //         cout << arr[i] << endl;
    //         visited = true;

    //     }
    // }

    // if(visited == false){

    //     cout << arr[0] << endl;

    // }

    //Geeks for Geeks solution.

    //Made for bool not gives exact value.

    int sum = 0;

    for (int i = 0; i < n; i++)
    {

        sum += arr[i];
    }

    int l_sum = 0;

    for(int i=0; i<n; i++){

        l_sum += arr[i];

        if(l_sum == sum - arr[i]){
            cout << arr[i] << endl;
            cout << i << endl;
        }

    }

    return 0;
}
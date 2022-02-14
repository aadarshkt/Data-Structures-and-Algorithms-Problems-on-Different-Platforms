#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[] = {8, 3, 4, 8, 8, 4, 4, 4, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    // int count = 1;

    // //O(n2) solution.

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[j] == arr[i])
    //         {
    //             count++;
    //         }
    //     }

    //     if (count > n / 2)
    //     {
    //         cout << arr[i] << " is the Major element" << endl;
    //     }

    //     count = 1;
    // }


    //Moore voting Algorithm.

    //First we find the most frequent element then we check whether it is major or not.

    //Moore voting alogrithm is based on the fact that if one element appears greater than n / 2 times.
    //Then surely other numbers, whatever they be, must have appeared less than n / 2 times. Now in whatever way
    // you put those less than n / 2 numbers. the numbers which occur more than n / 2 time must be repeated.
    //Since it must be reapeated. WE expolit this property.


    int arr1[] = {2, 4, 2, 2, 9, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int count = 1;

    int res = 0;

    for(int i=1; i<n1; i++){

        if(arr1[i] == arr1[res]) count++;
        else count--;

        if(count == 0){
            count = 1;
            res = i;
        }
        
    }

    count = 0;

    for(int i=0; i<n1; i++){
        if(arr1[i] == arr1[res]){
            count++;
        }
    }

    if(count > n1/2){
        cout << "Major element is " << arr1[res];
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int main()
{


    int arr[] = {30, 20, 17, 37};

    int n = sizeof(arr) / sizeof(arr[0]);

    //But both below works for only positive differences.

    //First long solution.

    // vector<int> temp = {};

    // for(int i=0; i<n; i++){
    //     int max = 0;
    //     for(int j=i+1; j<n; j++){

    //         int currDiff = arr[j] - arr[i];

    //         if(currDiff > max){
    //             max = currDiff;
    //         }

    //     }

    //     temp.push_back(max);
    // }

    // cout << *max_element(temp.begin(), temp.end()) << endl;

    // int max = arr[0], min = arr[0];

    // for(int i=1; i<n; i++){
    //     if(arr[i] > max){
    //         max = arr[i];
    //     } else if(arr[i] < min){
    //         min = arr[i];
    //     }
    // }

    // cout << max - min << endl;

    /* Theta(n * n) solution. */

    

    int max1;


    max1 = arr[1] - arr[0];



    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            max1 = max(max1, arr[j] - arr[i]);
        }
    }

    cout << max1 << endl;


    //Most Efficient solution.

    int min = arr[0];

    int max2 = arr[1] - arr[0];

    for(int i=1; i<n; i++){

        max2 = max(max2, arr[i] - min);

        if(arr[i] < min){
            min = arr[i];
        }
    }

    cout << max2 << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int main()
{

    //Quadratic Solution.


    int arr[] = {5, -10, 6, 90, 3, 1000};

    int n = sizeof(arr) / sizeof(arr[0]);

    // int sumMax = INT16_MIN, sum3 = 0;

    // for(int i=0; i<n; i++){
    //     int temp = i;
    //     sum3 = 0;
    //     for(int j=0; j<2; j++){

    //         sum3 += arr[i];
    //         i++;

    //     }

    //     if(sum3 > sumMax){
    //         sumMax = sum3;
    //     }

    //     i = temp;
    // }

    // cout << sumMax << endl;

    //More Good solution but no elements in the windows is to be changed everytime in the program.


    // for(int i=0; i<n-2; i++){

    //     sum3 = 0;

    //     sum3 = arr[i] + arr[i+1];

    //     if(sum3 > sumMax){
    //         sumMax = sum3;
    //     }


    // }

    // cout << sumMax << endl;


    //Better solution.

    //Basic technique is to move to next window first should be deleleted and end should be added.

    int k = 2, curr_Sum = 0, sumMax = INT16_MIN, given_Sum = 1004;

    bool visited = false;

    for(int i=0; i<k; i++){

        curr_Sum += arr[i];

    }

    if(given_Sum == curr_Sum){
            cout << "Yes" << endl;
        }

    for(int i=k; i<n; i++){

        

        curr_Sum = curr_Sum + arr[i] - arr[i - k];

        if(given_Sum == curr_Sum){
            cout << "Yes" << endl;
        } 
        
        else {

            if(visited == false)
                cout << "NO" << endl;
                visited = true;
        }

    }

    // cout << sumMax << endl;


    return 0;
}
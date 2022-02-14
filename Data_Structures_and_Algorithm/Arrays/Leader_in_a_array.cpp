#include <bits/stdc++.h>
using namespace std;
 
int main()
{


    int arr[] = {1, 10, 3, 40, 7, 10, 6, 20};

    int n = sizeof(arr) / sizeof(arr[0]);

    bool Leader[n] = {};


    for(int i=0; i<n; i++){

        

        for(int j=i+1; j<n; j++){
            if(arr[j] == arr[i]){
                Leader[i] = 1;
                Leader[j] = 1;
                break;
            } else if(arr[j] > arr[i]){
                Leader[i] = 1;
            }
        }


        if(Leader[i] == false) cout << arr[i] << " is a Leader." << endl;
    }



    //Efficient solution.

    //But prints in revese order.

    //simply travese from the end check if next last element is greater than the last element and assign it as leader.

    cout << arr[n-1] << " is a Leader." << endl;

    int curr_leader = arr[n-1];
    
    for(int i=n-2; i>=1; i--){

        if(arr[i-1] > curr_leader){
             curr_leader = arr[i-1];
             cout << arr[i-1] << " is a Leader." << endl;
        }

    }

    

    return 0;
}
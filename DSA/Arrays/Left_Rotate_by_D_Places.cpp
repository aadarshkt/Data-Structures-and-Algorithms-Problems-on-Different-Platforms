#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int low, int high){

    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }

}
 
int main()
{


    int arr[] = {1, 2, 3, 4, 5, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    //time - theta(n * d) space - theta(1);
    //First - solution

    int d = 2;

    // for(int j=0; j<d; j++){

    //     int first = arr[0];

    // for(int i=0; i<n; i++){
    //     arr[i] = arr[i+1];
    // }

    // arr[n-1] = first;

    // }


    //second - Time - theta(n) space - theta(n)

    // int temp[n];

  
    // for(int i=0; i<n; i++){

    //     if(i <= n-1-d){
    //         temp[i] = arr[i+d];
    //     } else if(i > n-1-d){
    //         temp[i] = arr[i-2-d];
    //     }
        

        
        
    // }


    //Third time - theta(n) space - theta(1);

    //Killer solution.


   reverse(arr, 0, d-1);
   reverse(arr, d, n-1);
   reverse(arr, 0, n-1);
   
    


    
    // for(int x : temp) cout << x << " ";
    

    for(int x : arr) cout << x << " ";

    return 0;
}
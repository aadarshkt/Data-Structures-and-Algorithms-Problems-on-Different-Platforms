//THis is a solution of checking how many subsets are possible for a given sum.

#include <bits/stdc++.h>
using namespace std;

 

int subsets(int arr[], int n, int sum = 25){

    
  
 
    if(n == 0){
        return ((sum == 0) ? 1 : 0);
    } 

    


    return (subsets(arr, n-1, sum) + subsets(arr, n-1, sum - arr[n-1]));
 

}
 
int main(){

 int arr[] = {10, 20 , 15, 5};

 int n = sizeof(arr) / sizeof(arr[0]);
 
 cout << subsets(arr, n);
 
 return 0;
}
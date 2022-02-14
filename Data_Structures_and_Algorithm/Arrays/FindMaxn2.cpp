#include <bits/stdc++.h>
using namespace std;

//O(N^2) solution.

int getmax(int arr[], int n){

   for(int i=0; i<n; i++){
       bool flag = true;
       for(int j=i+1; j<n; j++){
           if(arr[j] > arr[i]){
               flag = false;
               break;
           }
       }

       if(flag == true){
           return i;
       }
   }



   return -1;

}
 
int main(){

 int arr[] = {1, 2, 3, 4, 5};

 int n = sizeof(arr)/sizeof(arr[0]);
 
 cout << getmax(arr, n);
 
 return 0;
}
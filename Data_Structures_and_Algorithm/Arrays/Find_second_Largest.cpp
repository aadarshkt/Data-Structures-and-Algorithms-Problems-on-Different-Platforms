#include <bits/stdc++.h>
using namespace std;

//Time  - theta(n) a . s = theta(1) because as input space allocated remains constant.
 
int main(){
 
 int arr[] = {1, 2, 3, 4, 7, 9, 14, 10};

 int n = sizeof(arr) / sizeof(arr[0]);

 int largest = 0, res = -1;

 for(int i=1; i<n; i++){

     if(arr[i] > arr[largest]){
         res = largest;

         largest = i;
         
     } else if(arr[i] < arr[largest]){

         if(res == -1){
             res = i;
         } else if(arr[i] > arr[res]){
             res = i;
         }

     }

 }

 cout << arr[res] << endl;
 
 return 0;
}
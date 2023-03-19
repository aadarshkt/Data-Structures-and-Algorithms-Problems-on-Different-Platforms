#include <bits/stdc++.h>
using namespace std;

//Time - theta(n)
//space - theta(2n)
 
int main(){
 
 int arr[] = {1, 2, 3, 4, 5, 6, 7};

 int n = sizeof(arr) / sizeof(arr[0]);


 int revarr[n];

 for(int i=0; i<n; i++){

     revarr[i] = arr[n-1-i];
     cout << revarr[i] << " ";

 }


 
 return 0;
}
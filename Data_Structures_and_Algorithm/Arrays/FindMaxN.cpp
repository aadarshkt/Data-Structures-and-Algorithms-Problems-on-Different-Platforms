#include <bits/stdc++.h>
using namespace std;

//O(N) solution Emoji with black Glasses.

int getmax(int arr[], int n){

    int a = 0;

 
    for(int i=1; i<n; i++){

        if(arr[i] > arr[0]){
            a = i;
        }

    }


    return a;



}
 
int main(){
 
 int arr[] = {1, 2, 3, 4, 5};

 int n = sizeof(arr)/sizeof(arr[0]);
 
 cout << getmax(arr, n);
 
 return 0;
}
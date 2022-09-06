#include <bits/stdc++.h>
using namespace std;

vector<int> reverseArray(int arr[], int &n){

    vector <int> v = {0};

    for(int i=0; i<n; i++){
        v[n-1-i] = arr[i];
    }

    return v;

}
 
int main(){
 
 int arr[] = {1, 2, 3, 4, 5};

 int n = sizeof(arr) / sizeof(arr[0]);

 cout << reverseArray(arr, n)[2] << endl;
 
 
 
 return 0;
}
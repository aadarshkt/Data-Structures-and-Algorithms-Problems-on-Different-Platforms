#include <bits/stdc++.h>
using namespace std;

int query(int start, int end, int arr[]){

    if(start == 0){
        return arr[end];
    }

    return arr[end] - arr[start-1];

}
 
int main()
{


    int arr[] = {2, 8, 3, 9, 6, 5, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    //Make prefix sum array.

    int prefixSum[n];

    prefixSum[0] = arr[0];

    for(int i=1; i<n; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    
    cout << query(0, 2, prefixSum);
    
    //For query zero at start we have to make another case.

    return 0;
}
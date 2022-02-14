#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    //My own solution first time. Writing your solution makes you love coding. !!!


    int arr[] = {10, 50, 50 , 50};

    int n = sizeof(arr) / sizeof(arr[0]);

    int count = 1;

    int curr = arr[0];
 
    for(int i=1; i<n; i++){

        if(arr[i] == curr){
            count++;
        } else if(arr[i] != curr){
            cout << arr[i-1] << " " << count << endl;
            count = 0;
            curr = arr[i];
            count++;

        }

    }

    cout << arr[n-1] << " " << count << endl;

    //There is also a solution using arrays.

    return 0;
}
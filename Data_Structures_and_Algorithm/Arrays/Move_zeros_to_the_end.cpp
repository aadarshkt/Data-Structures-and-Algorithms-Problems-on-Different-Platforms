#include <bits/stdc++.h>
using namespace std;
 
int main()
{


    //My own solution.All hapiness of coding lies in writing all code all by yourself.


    int arr[] = {0, 0, 0, 0, 0, 0, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i=n-1; i>=1; i--){
        if(arr[i] != 0){
            if(arr[i-1] == 0){
                arr[i-1] = arr[i];
                arr[i] = 0;
                if(i<n-1 && arr[i+1] != 0){
                    arr[i] = arr[i+1];
                    arr[i+1] = 0;
                }
            }
        }
    }


    for(int x : arr){
        cout << x << " ";
    }

    cout << endl;


    //Both above and below solution has time - O(n) and A.space - O(1)


    int arr1[] = {0, 0, 0, 0, 0, 0, 1};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int count = 0;

    for(int i=0; i<n1; i++){
        if(arr1[i] != 0){
            swap(arr1[i], arr1[count]);
            count++;
        }
    }

    for(int x : arr1) cout << x << " ";

    return 0;
}
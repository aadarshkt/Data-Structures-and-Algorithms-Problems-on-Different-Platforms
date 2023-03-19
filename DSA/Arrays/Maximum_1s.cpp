#include <bits/stdc++.h>
using namespace std;
 
int main()
{


    int arr[] = {0, 1, 1, 0, 1, 1, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    int count = 0;

    int max1 = 0;

    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            count++;
        } else if(arr[i] != 1){
            if(max1 < count){
                max1 = count;
                count = 0;
            }
        }
    }

    int maxi = max(max1, count);


    cout << maxi << endl;



    return 0;
}
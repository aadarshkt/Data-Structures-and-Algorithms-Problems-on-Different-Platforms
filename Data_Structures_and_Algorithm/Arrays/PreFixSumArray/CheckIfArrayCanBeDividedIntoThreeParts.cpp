#include <bits/stdc++.h>
using namespace std;
 
int main()
{


    int arr[] = {1, 2, 2, 3, 2, 6, -1};

    int n = sizeof(arr) / sizeof(arr[0]);

    int prefixSum[n];

    int sum = 0, num, count;

    for(int i=0; i<n; i++){

        sum += arr[i];

        prefixSum[i] = sum;


    }

    for(int x : prefixSum) cout << x << " ";

    cout << endl;

    for(int i=0; i<n; i++){

        num = prefixSum[i];

        count = 0;


        for(int j=i+1; j<n; j++){
            if(prefixSum[j] % num == 0){
                count++;
                cout << "BYE" << endl;
            }
        }

        if(count == 3){
            cout << i << endl;
        }

    }


    return 0;
}
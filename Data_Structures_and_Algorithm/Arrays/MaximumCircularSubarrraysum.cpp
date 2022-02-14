#include <bits/stdc++.h>
using namespace std;

int circularSubarraySum(int arr[], int num){
        
        // your code here
        int sum, maxSum = INT_MIN;
        
        for(int i=0; i<num; i++){
            sum = 0;
            for(int j=0;j<num; j++){
                int index = (i+j) % num;
                sum += arr[index];
                if(sum > maxSum){
                    maxSum = sum;
                }
            }
        }
        
        return maxSum;
    }
 
int main()
{

    int arr[] = {8,-8,9,-9,10,-11,12};

    int num = sizeof(arr) / sizeof(arr[0]);

    cout << circularSubarraySum(arr, num);

    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int main()
{


    int a = 2;

    printf("How many do you want Fibonacci Number\n");

    int n;

    scanf("%d", &n);

    int arr[n];

    arr[0] = 1;
    arr[1] = 1;

    int curr_sum = 2;

    arr[2] = curr_sum;

    for(int i=3; i<n; i++){
        curr_sum += arr[i-1] - arr[i-3];

        arr[i] = curr_sum;
    }

    for(int x : arr) cout << x << endl;


    return 0;
}
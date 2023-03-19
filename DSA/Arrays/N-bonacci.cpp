#include <bits/stdc++.h>
using namespace std;
 
int main()
{


    int N, M;

    scanf("%d %d", &N, &M);

    int arr[M];

    for(int i=0; i<N-1; i++){
        arr[i] = 0;
    }

    arr[N-1] = 1;

    

    int curr_sum = 0;

    for(int i=0; i<N; i++){
        curr_sum += arr[i];
    }

    arr[N] = curr_sum;

    for(int i=N+1; i<M; i++){
        curr_sum = curr_sum-arr[i-N-1]+arr[i-1];

        arr[i] = curr_sum;
    }

    for(int x : arr) cout << x << endl;


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//Better use hashing.

void findPair(int arr[], int n, int x)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] + arr[j] == x)
            {
                cout << i << " " << j;
            }
        }
    }
}
 
int main()
{

    int arr[] = {3, 4, 6, 7, 10, 15,13, 26, 12};

    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 36;
    findPair(arr, n, sum);

    return 0;
}
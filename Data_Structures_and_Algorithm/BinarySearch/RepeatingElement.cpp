#include <bits/stdc++.h>
using namespace std;

//We can use janamPatri or Ledger.

int findRepeating(int arr[], int n)
{
     
    int ledger[n-1] = {0};

    for(int i=0; i<n; i++)
    {
        ledger[arr[i]]++;
    }

    for(int i=0; i<n-1; i++)
    {
        if(ledger[i] > 1)
        {
            return ledger[i];
        }
    }

return 0;

}

 
int main()
{

    int arr[] = {0, 2, 1, 3, 4, 5, 7, 4, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findRepeating(arr, n);
    
    return 0;
}
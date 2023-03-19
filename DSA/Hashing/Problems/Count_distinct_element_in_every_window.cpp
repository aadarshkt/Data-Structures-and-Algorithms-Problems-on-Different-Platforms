#include <bits/stdc++.h>
using namespace std;

///O(k) space and time is 0(n-k)

void count_distinct_window(int arr[], int n, int k)
{
    for(int i=0; i<=n-k; i++)
    {
        unordered_set<int> s(arr+i, arr+i+k);

        cout << s.size() << " ";
    }
}
 
int main()
{

    int arr[] = {10, 10, 10};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;

    count_distinct_window(arr, n, k);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//Time - O(n) space - O(n)

bool sub_sum(int arr[], int n, int sum)
{
    unordered_set<int> s;

    int prefix;
    
    for(int i=0; i<n; i++)
    {
        prefix += arr[i];

        s.insert(prefix);

        int a = prefix - sum;

        if(s.count(a))
        {
            return true;
        }
    }

    return false;
}
 
int main()
{

    int arr[] = {1, 8, 6, 13, -3, -10};

    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 16;

    cout << sub_sum(arr, n, sum);

    return 0;
}
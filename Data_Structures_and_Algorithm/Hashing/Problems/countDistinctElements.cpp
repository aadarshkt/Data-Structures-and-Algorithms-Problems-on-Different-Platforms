#include <bits/stdc++.h>
using namespace std;

//time O(n) space O(n)

void distinctElements(int arr[], int n)
{
    unordered_set<int> s(arr, arr+n);//shorter.

    // for(int i=0; i<n; i++)
    // {
    //     s.insert(arr[i]);
    // }

    cout << s.size();


}
 
int main()
{

    int arr[] = {10, 10, 12, 12, 15, 16, 17, 12};

    int n = sizeof(arr) / sizeof(arr[0]);

    distinctElements(arr, n);

    return 0;
}
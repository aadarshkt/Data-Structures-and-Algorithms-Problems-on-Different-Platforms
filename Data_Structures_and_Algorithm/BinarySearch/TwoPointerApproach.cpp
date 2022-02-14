#include <bits/stdc++.h>
using namespace std;

//Fastest sorting can be done in nlog time.
//Hashing can also be used but it will require extra O(n) space.

//O(nlogn) + O(n2) is O(n2)

bool findPair(int arr[], int n, int x)
{
    int r = n - 1;
    int l = 0;

    while (l < r)
    {

        if (x == (arr[l] + arr[r]))
        {
            cout << l << " " << r << endl;
            return true;
        }
        if (x < (arr[r] + arr[l]))
        {
            r = r - 1;
        }
        else
        {
            l = l + 1;
        }
    }

    return false;
}

//O(n2) solution.

bool findTriplet(int arr[], int n, int x)
{
    int l, r, a;
    for (int i = 0; i < n; i++)
    {
        a = arr[i];

        l = i + 1;
        r = n - 1;

        while (l < r)
        {

            if (x == (a + arr[l] + arr[r]))
            {
                cout << i << " " << l << " " << r << endl;
                return true;
            }
            if (x < (arr[r] + arr[l] + a))
            {
                r = r - 1;
            }
            else
            {
                l = l + 1;
            }
        }
    }

    return false;
}

int main()
{

    int arr[] = {3, 4, 6, 7, 10, 15, 26, 31};

    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 36;

    // cout << findPair(arr, n, sum);

    sum = 45;

    cout << findTriplet(arr, n, sum);

    return 0;
}
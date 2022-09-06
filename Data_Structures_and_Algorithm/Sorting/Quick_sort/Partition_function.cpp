#include <bits/stdc++.h>
using namespace std;

//We have to make all the elements smaller than the element at index i, to the left and greater than to the right.

//0(n) time and 0(n) space;

void partition(int arr[], int l, int r, int p)
{
    int n = r - l + 1;
    int temp[n], x = 0, smaller = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[p])
        {
            smaller++;
        }
    }

    y = smaller + 1;

    temp[smaller] = arr[p]; //Finding the correct position of the pivot.
    for (int i = 0; i < n; i++)
    {
        if (arr[p] > arr[i])
        {
            temp[x] = arr[i];
            x++;
        }
        else
        {
            temp[y] = arr[i];
            y++;
        }
    }

    for (int x : temp)
    {

        cout << x << " ";
    }
}


//More efficient is lamuto partition.



int main()
{

    int arr[] = {3, 8, 6, 12, 10, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    int p = n - 1;

    partition(arr, 0, n - 1, p);

    

    return 0;
}
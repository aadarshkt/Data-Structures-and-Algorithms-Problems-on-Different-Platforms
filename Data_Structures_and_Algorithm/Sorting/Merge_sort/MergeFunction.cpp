#include <bits/stdc++.h>
using namespace std;

//0(n) time and 0(n) space.

void Merge(int arr[], int l, int m, int h)
{
    int r = m + 1;

     while(l <= m && r <= h)
     {
         if(arr[l] <= arr[r])
         {
             cout << arr[l] << " ";
             l++;
         } else if(arr[r] < arr[l])
         {
             cout << arr[r] << " ";
             r++;
         }
     }

     if (l > m)
        for (int j = r; j < h+1; j++)
            cout << arr[j] << " ";
    if (r > h)
        for (int i = l; i < m+1; i++)
            cout << arr[i] << " ";
    
    
}

//Merge sort based function
//This function basically sorts a array if it sorted upto middle and middle + 1 to last.

void merge(int arr[], int l, int m, int h)
{

    int n1 = m - l + 1;
    int n2 = h - m;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[m + i + 1];
    }

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    while (j < n2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
}
 
int main()
{

    int arr[] = {10, 15, 20, 6, 7, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    int l = 0, h = n-1, m = (l+h)/2;

    merge(arr, l, m, h);

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
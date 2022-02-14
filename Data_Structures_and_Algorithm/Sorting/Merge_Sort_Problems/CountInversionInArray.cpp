#include <bits/stdc++.h>
using namespace std;


void printInversion(int arr[], int n)
{
    int count = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    cout << count << endl;
}

//Merge sort based

int count1 = 0, count2 = 0;

int fun(int arr[], int l, int m, int r)
{
    // if(arr[l] > arr[r])
    // {
    //     count2++;
    // }
    
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[m + i + 1];
    }
    
    int res = 0;
    int i = 0, j = 0, k = l;

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
            res = res + (n1 - i);//basically when we are merging for every element in right[i] we check whether there are gre
            //ater elements in left (basically two left and right subarrays are part of a array sorted upto mid)
            // if there is greater elements in right we uptdate res with all next left elements to be added(because all left 
            // will be obviously be greater than left.) simply take example of |2|5|8|11| and |3|6|9|13| for 3 in right 5, 8, 11, (thus we do n1 - i)are greater 
            // and thus form inversions of larger array made from left and right array.
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

    return res;
    
}

int  printInversionEfficient(int arr[], int l, int r)
{
    int res = 0;
    if(r <= l)
    {
        return 0;
    }
    if(r > l)
    {
        int m = l + (r-l)/2;
        res += printInversionEfficient(arr, l, m);
        res += printInversionEfficient(arr, m+1, r);
        res += fun(arr, l, m, r);
    }

    return res;
   
}
 
int main()
{

    int arr[] = {10, 5, 30, 11, 9, 8, 32};

    int n = sizeof(arr) / sizeof(arr[0]);

    printInversion(arr, n);

    cout << printInversionEfficient(arr, 0, n-1);

    return 0;
}
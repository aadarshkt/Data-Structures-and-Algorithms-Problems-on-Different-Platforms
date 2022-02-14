#include <bits/stdc++.h>
using namespace std;

//O(n^2) algo
//1-> sorted and unsorted part.
//2-> for every i we start from j = i-1 to 0.
//3-> we also copy j to j+1.
//4-> as long as arr[j] > key.
//5-> It is also like bubble but the bubble starts from middle part i and goes to its correct positon.
// 
///TO understand this algo simply do it for 5, 15, 17, 10. do it for 10. i is at 10.
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int arr[] = {2, 10, 8, 7, 5, 35, 25, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    return 0;
}
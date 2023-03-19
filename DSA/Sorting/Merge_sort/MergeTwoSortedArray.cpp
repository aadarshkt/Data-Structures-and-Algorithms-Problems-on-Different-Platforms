#include <bits/stdc++.h>
using namespace std;

//O(nlogn) algo

void mergeSort(int arr1[], int arr2[], int n1, int n2)
{
    int n = n1 + n2;
    int array[n];

    for (int i = 0; i < n1; i++)
    {
        array[i] = arr1[i];
    }

    for (int i = 0; i < n1; i++)
        cout << array[i] << " ";
    cout << endl;
    
    //Better approach is just add two arrays and do sort(arr, arr+n) O(nlogn);

    for (int i = 0; i < n2; i++)
    {
        int j = n1 + i - 1;
        int key = arr2[i];
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }

    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}

void mergeSortEfficient(int arr1[], int arr2[], int n1, int n2)
{
    int n = n1 + n2;

    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {

        if (arr1[i] <= arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        if (arr1[i] > arr2[j])
        {

            cout << arr2[j] << " ";
            j++;
        }
    }

    if (i >= n1)
        for (j = j; j < n2; j++)
            cout << arr2[j] << " ";
    if (j >= n2)
        for (i = i; i < n1; i++)
            cout << arr1[i] << " ";
}

int main()
{

    int arr1[] = {1, 3, 5, 6};

    int arr2[] = {2, 4, 9, 15, 20, 35};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    mergeSort(arr1, arr2, n1, n2); //O((m+n) * log(m+n)) time and 0(m+n) space.

    mergeSortEfficient(arr1, arr2, n1, n2); //0(m+n) and 0(1) space.

    return 0;
}
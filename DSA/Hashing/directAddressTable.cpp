#include <bits/stdc++.h>
using namespace std;

//do insert, search and delete in O(1) time.

void insert(int arr[], int k)
{
    arr[k] = 1;
}

bool search(int arr[], int k)
{
    if (arr[k] == 1)
        return true;
}

void delete1(int arr[], int k)
{
    arr[k] = 0;
}

int main()
{

    int arr[1000];

    insert(arr, 10);

    cout << search(arr, 10);

    delete1(arr, 10);

    cout << endl;

    cout << search(arr, 10);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//Geeks for Geeks killer solution.

//Basically ++ increases upto the required  and then R[i]+1-- nullifies that carryone prefix sum.so in this way all elements in
//in that  have frequency increased by one.

void findOcc(int L[], int R[], int n)
{

    int arr[10] = {};

    for (int i = 0; i < n; i++)
    {

        arr[L[i]]++;
        arr[R[i] + 1]--;
    }

    for (int x : arr)
        cout << x << " ";

    cout << endl;

    int sum = arr[0];
    int max = arr[0], res;

    for (int i = 1; i < 10; i++)
    {

        sum += arr[i];

        arr[i] = sum;

        if (arr[i] > max)
        {
            max = arr[i];
            res = i;
        }
    }

    cout << res << endl;
}

int main()
{

    int L[] = {1, 4, 5};

    int n = sizeof(L) / sizeof(L[0]);

    int R[] = {3, 5, 7};

    findOcc(L, R, n);

    return 0;
}
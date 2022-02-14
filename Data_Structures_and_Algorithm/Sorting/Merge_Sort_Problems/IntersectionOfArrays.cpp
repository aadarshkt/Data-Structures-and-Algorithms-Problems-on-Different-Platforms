#include <bits/stdc++.h>
using namespace std;

///Find the intersection of two arrays.if a particular element is repeated.show it only once.

void findIntersection(int a[], int b[], int n, int m)
{
    int i = 0, j = 0, d = 0;
     
    while (i < n && j < m)
    {
        if(i > 0 && a[i] == a[i-1]) {
            i++;
            continue;
        }
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }

        if (a[i] > b[j])
        {
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
    }
}

int main()
{

    int a[] = {1, 1, 3, 3, 3, 7, 15, 97};
    int b[] = {1, 1, 3, 5, 7, 97};

    int n = sizeof(a) / sizeof(a[0]);

    int m = sizeof(b) / sizeof(b[0]);

    findIntersection(a, b, n, m);

    return 0;
}
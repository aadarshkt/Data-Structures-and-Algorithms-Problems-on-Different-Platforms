#include <bits/stdc++.h>
using namespace std;

//0(m+n); space O(1)

void printUnion(int a[], int b[], int n, int m)
{
    int i = 0, j = 0, d = 0;
     
    while (i < n && j < m)
    {
        if(i > 0 && a[i] == a[i-1])
        {
            i++;
            continue;
        }
        if(j > 0 && b[j] == b[j-1])
        {
            j++;
            continue;
        }
        if(a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        } else if(b[j] < a[i])
        {
            cout << b[j] << " ";
            j++;
        } else 
        {
            cout << a[i] << " ";
            i++;
            j++;
        }

    }

    

    while(i < n)
    {
        if(i > 0 && a[i] != a[i-1])
        {
             cout << a[i] << " ";
             i++;
        } else 
        {
            i++;
        }
       
    }
    while(j < m)
    {
        
        if(j > 0 && b[j] != b[j-1])
        {
           cout << b[j] << " ";
           j++;
        } else 
        {
            j++;
        }
        
    }

}
 
int main()
{

    int a[] = {2, 3, 3, 3 ,4, 4};
    int b[] = {4, 4, 97, 101};

    int n = sizeof(a) / sizeof(a[0]);

    int m = sizeof(b) / sizeof(b[0]);

    printUnion(a, b, n, m);

    return 0;
}
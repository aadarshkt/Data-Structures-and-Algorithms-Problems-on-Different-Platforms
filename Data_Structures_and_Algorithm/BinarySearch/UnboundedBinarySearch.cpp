#include <bits/stdc++.h>
using namespace std;

//My solution not so good ;

// int Occ(int arr[], int l, int x)
// {
//     int m = 1;
//     while (true)
//     {
//         int r = (2 * m) - l;

//         if (arr[r] == x)
//         {
//             return r;
//         } else if(arr[r] > x){
//            while(l <= r)
//            {
//                m = (l+r) / 2;

//                if(arr[m] == x)
//                {
//                    return m;
//                }

//                if(arr[m] < x){
//                    l = m + 1;
//                } else {
//                    r = m - 1;
//                }
//            }

//            return -1;
//         }
//         else
//         {
//             m++;
//         }
//     }
// }

//GeeksForGeeks solution better.

int binarySea(int arr[], int l, int r, int x)
{
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;

        if(l == r)
        {
            cout << l << "holi" << r << endl;
        }

        if (arr[m] == x)
        {
            cout << "Bye" << endl;
            return m;
        }

        if (arr[m] < x)
        {
            cout << "askgh" ;
            l = m + 1;
        }
        else
        {
            cout << "2" << endl ;
            r = m - 1;
        }
    }



    return -1;
}

int Occ(int arr[], int x, int n)
{
    if(arr[0] == x)
    {
        return 0;
    }
    int i = 1;
    while(true)
    {
        if(arr[i] == x)
        {
            cout << "Hello" << endl;
            return i;
        }

        if(arr[i] > x )
        {
            cout << "1" ;
            return binarySea(arr, (i/2)+1, i-1, x);
        }

        i = i * 2;
    }
}


//Make sure array is sufficiently larger.

int main()
{

    int arr[] = {2, 4, 5, 6, 12, 34, 45, 64, 69, 71, 82, 93, 102, 113, 200, 223, 243, 245, 267, 278, 289};

    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 93;

    cout << "Index of the occurrence is : " << Occ(arr, x, n);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//sort c++ stl can be used in array, vector, and deque which provides random a
//access means accessing that element in constant time.
//sort function uses introsort (hybrid of quick sort, heap sort, Insertion sort);

struct Point{

        int p, q;

    };

bool mycmp(Point p1, Point p2)
{
    return (p1.p < p2.q);
}
 
int main()
{
    /** Array sort **/

    int arr[] = {2, 3, 43, 1, 5, 78};

    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr+n);//arr+n is address of beyond last element.

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    sort(arr, arr+n, greater<int>());

    cout << endl;

    for(int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;

    /** Vector sort **/

    vector<int> v = {2, 31, 34, 21, 45, 73};

    sort(v.begin(), v.end());//also u can add greater<int>() which reverse the default order.

    for(int x : v) cout << x << " ";

    /** structure sort **/

    Point arr1[] = {{3, 10}, {4, 43}, {9, 32}, {7, 39}};

    int b = 4;

    sort(arr1, arr1+b, mycmp);

    for(auto a : arr1)
    {
        cout << a.p << " " << a.q << "  ";
    }
 
    
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[4] = {1, 2, 3, 4};

    swap(arr[0], arr[1]);

    for(int i=0; i<4; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
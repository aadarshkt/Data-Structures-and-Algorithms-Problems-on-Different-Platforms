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

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for(int i=0; i<n; i++) cin >> arr[i];

        debug(n);
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int d, e, f = 0;

int maxCuts(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n < 0)
    {
        return -1;
    }

    int res = max(1 + maxCuts(n - a, a, b, c), (  1 + maxCuts(n - b, a, b, c), 1 + maxCuts(n - c, a, b, c)));

    if (res == 0)
    {
        return -1;
    }

    return res ;
}

int main()
{

    cout << maxCuts(23, 9, 11, 12);

    return 0;
}
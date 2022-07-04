#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a;
    cin >> a;

    int b = 3;

    int c, d, e, f = 0;

    while (a--)
    {
        cin >> c >> d >> e;
        if (c + d + e > 1)
            f++;
    }

    cout << f << endl;
    return 0;
}
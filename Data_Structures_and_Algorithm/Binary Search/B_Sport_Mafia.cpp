#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long eatMove = 0, lo = 0, hi = n - 1;

    while (lo <= hi)
    {
        eatMove = lo + (hi - lo) / 2;
        long long putMove = n - eatMove;

        long long totalPutCandy = putMove * (putMove + 1) / 2, remain = totalPutCandy - eatMove;

        if (k == remain)
        {
            cout << eatMove << endl;
            break;
        }
        else if(k < remain)
        {
            lo = eatMove + 1;
        }
        else if(k > remain)
        {
            hi = eatMove - 1;
        }
    }

    return 0;
}
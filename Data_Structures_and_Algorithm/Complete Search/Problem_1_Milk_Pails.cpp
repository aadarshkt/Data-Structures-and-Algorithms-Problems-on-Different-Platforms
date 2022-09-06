#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include <bits/debug.h>
#else
#define debug(x)
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("div7.in", "r", stdin);
    // // the following line creates/overwrites the output file
    // freopen("div7.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;

    int ans = 0;

    for(int i=0; i<1001; i++)
    {
        if(x * i > m) break;
        for(int j=0; j<1001; j++)
        {
            int n = x * i + y * j;
            if(n > m) break;
            ans = max(ans, n);
        }
    }

    cout << ans << endl;

    return 0;
}
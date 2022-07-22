#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, b;
    cin >> n >> k >> b;

    bool flag[n] = {0};

    int tempb = b;

    while(b--)
    {
        int r;
        cin >> r;
        flag[r - 1] = 1;
    }

    int prefix[n], sum = 0;

    for(int i=0; i<n; i++)
    {
        if(flag[i])
        {
            sum += 1;
        }

        prefix[i] = sum;
        cout << prefix[i] << " ";
    }

    cout << endl;

    int i = 0, j = k - 1;

    int ans = INT_MAX;

    while(j < n)
    {
        ans = min(ans, prefix[j] - prefix[i]);
        i++, j++;
    }

    cout << ans << endl;

    return 0;
}
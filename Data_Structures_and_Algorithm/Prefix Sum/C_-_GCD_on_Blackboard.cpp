#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int prefix[n], suffix[n];

    prefix[0] = arr[0];
    suffix[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = __gcd(prefix[i - 1], arr[i]);
        suffix[n - i - 1] = __gcd(suffix[n - i], arr[n - i - 1]);
    }

    int ans = prefix[n-2];

    for (int i = 1; i < n - 1; i++)
    {
        ans = max(ans, __gcd(prefix[i - 1], suffix[i + 1]));
    }

    ans = max(ans, suffix[1]);

    cout << ans << endl;

    return 0;
}
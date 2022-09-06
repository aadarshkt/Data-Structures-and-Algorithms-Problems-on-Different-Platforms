#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<long long, int> m;

    long long prefix = 0, ans = 0;

    m[0] = 1;

    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        ans += m[prefix - x];
        m[prefix]++;
    }

    cout << ans << endl;

    return 0;
}
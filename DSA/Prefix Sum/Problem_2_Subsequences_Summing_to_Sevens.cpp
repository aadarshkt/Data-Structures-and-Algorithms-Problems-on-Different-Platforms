#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("div7.in", "r", stdin);
    // // the following line creates/overwrites the output file
    // freopen("div7.out", "w", stdout);

    int n;
    cin >> n;

    int arr[n];

    long long sum = 0, prefix[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        prefix[i] = sum;
        prefix[i] = prefix[i] % 7;
    }

    int count = 0, maxDiff = 0;

    map<int, pair<int, int>> m;

    for (int i = 0; i < n; i++)
    {
        if (m.count(prefix[i]))
        {
            m[prefix[i]].second = i;
        }
        else
        {
            m[prefix[i]].first = i;
            m[prefix[i]].second = i;
        }
        maxDiff = max(maxDiff, m[prefix[i]].second - m[prefix[i]].first);
    }

    cout << maxDiff << endl;

    return 0;
}
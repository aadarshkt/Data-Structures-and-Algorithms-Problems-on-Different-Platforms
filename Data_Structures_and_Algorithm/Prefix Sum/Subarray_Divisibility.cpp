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
    long long sum = 0, prefix[n];

    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        prefix[i] = (sum % n + n) % n;
    }
    map<long long, long long> f;

    //individual is also calculated with this trick.
    f[0] = 1;

    for (int i = 0; i < n; i++)
    {
        f[prefix[i]]++;
    }

    for (auto it = f.begin(); it != f.end(); it++)
    {
        long long t = it->second;
        //no of ways to chose two elements.
        count += t * (t - 1) / 2;
    }

    cout << count << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int arr[n];

        long long sum = 0;

        map<int, int> f;

        f[1] = 1;

        for(int i=0; i<n; i++)
        {
            arr[i] = s[i] - '0';
            sum += arr[i];
            f[sum - i]++;
        }

        long long count = 0;

        for(auto it = f.begin(); it != f.end(); it++)
        {
            long long t = it->second;
            count += t * (t - 1) / 2;
        }

        cout << count << endl;
    }

    return 0;
}
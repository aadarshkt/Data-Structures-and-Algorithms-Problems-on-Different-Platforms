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
    {
        cin >> arr[i];
    }

    int i = 0, j = 0;

    long long sum = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        while (sum > x and j < n)
            sum -= arr[j++];
        if (sum == x)
            count++;
    }
    cout << count << endl;

    return 0;
}
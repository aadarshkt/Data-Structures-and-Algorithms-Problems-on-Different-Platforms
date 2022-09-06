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

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    set<int> s;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = arr[i];
        s.insert(arr[i]);
        for (int j = i + 1; j < n; j++)
        {
            s.insert(arr[j]);
            sum += arr[j];
            // cout << sum << " ";
            int n = j - i + 1;
            double avg = double(sum) / n;
            int avg1 = int(sum) / n;
            double diff = avg - avg1;
            if (diff == 0 && s.count(avg))
            {
                count++;
            }
        }

        s.clear();
    }

    cout << count + n << endl;
    return 0;
}
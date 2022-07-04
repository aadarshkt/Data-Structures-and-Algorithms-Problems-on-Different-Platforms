#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long q;
    cin >> q;

    vector<int> s;

    while (q--)
    {
        int first;
        cin >> first;

        if (first == 1)
        {
            int b;
            cin >> b;

            s.push_back(b);
        }
        else if (first == 3)
        {
            int maxNum = INT_MIN;
            int minNum = INT_MAX;

            int n = s.size();

            for (int i = 0; i < n; i++)
            {
                maxNum = max(maxNum, s[i]);
                minNum = min(minNum, s[i]);
            }

            cout << maxNum - minNum << endl;
        }
        else if (first == 2)
        {
            long long x, c;
            cin >> x >> c;

            int n = s.size();

            long long a = 0;

            for (int i = 0; i < n; i++)
            {
                if (s[i] == x)
                    a++;
            }

            int m = min(c, a);

            for (auto it = s.begin(); it != s.end(); ++it)
            {
                if (*it == x)
                {
                    if (m > 0)
                    {
                        s.erase(it);
                        it--;
                        m--;
                    }
                }

            }
        }
    }

    return 0;
}
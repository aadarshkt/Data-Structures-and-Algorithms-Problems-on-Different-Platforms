#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w;
    cin >> h >> w;

    string arr[h];

    for (int i = 0; i < h; i++)
    {
        cin >> arr[i];
    }

    int x1 = -1;
    int x2 = -1;
    int y1 = -1;
    int y2 = -1;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] == 'o')
            {
                if (x1 != -1)
                {
                    x2 = i;
                    y2 = j;
                }
                else
                {
                    x1 = i;
                    y1 = j;
                }
            }
        }
    }

    cout << abs(x1 - x2) + abs(y1 - y2);

    return 0;
}
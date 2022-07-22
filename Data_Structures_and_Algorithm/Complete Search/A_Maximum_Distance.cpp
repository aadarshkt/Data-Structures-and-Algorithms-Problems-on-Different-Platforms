#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int x[n], y[n];

    for(int i=0; i<n; i++) cin >> x[i];
    for(int i=0; i<n; i++) cin >> y[i];

    int diffS[n];

    int maxNum = INT_MIN;

    for(int i=0; i<n; i++)
    {
       int a = x[i], b = y[i];

        for(int j = 0; j<n; j++)
        {
            if(j != i)
            {
                int c = x[j], d = y[j];
                int dist = pow(abs(c - a), 2) + pow(abs(d - b), 2);
                maxNum = max(maxNum, dist);
            }
        }
    }

    cout << maxNum << endl;


    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int h[n];
    int dp[n]; //minCost at a pos.

    for(int i=0; i<n; i++) cin>>h[i];

    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);

    for(int i=2; i<n; i++)
    {
        int lastCost = abs(h[i] - h[i-1]);
        int secondLastCost = abs(h[i] - h[i-2]);

        dp[i] = min(lastCost + dp[i-1], secondLastCost + dp[i-2]);
    }

    cout << dp[n-1] << endl;

    


    return 0;
}
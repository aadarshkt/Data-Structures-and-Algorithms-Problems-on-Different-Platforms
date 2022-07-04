#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 1;
int dp[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<dp[n]<<endl;

    return 0;
}
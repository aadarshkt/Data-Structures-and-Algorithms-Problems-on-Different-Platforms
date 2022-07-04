#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 1;
int dp[MAX][3]; //dp[i][j] represents the value of most happiness points with ith day performing jth activity.
int points[MAX][3];

int maxHap(int n, int j)
{

    if(n == 0)
    {
        return points[n][j];
    }

    if(dp[n][j] != -1) return dp[n][j];

    int ans = 0;

    for(int k=0; k<3; k++)
    {
        if(k != j)
        {
            ans = max(ans, maxHap(n-1, k) + points[n][j]) ;
        }
    }

    return dp[n][j] = ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i=0; i<MAX; i++) 
        for(int j=0; j<3; j++)
            dp[i][j] = -1;

    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            cin>>points[i][j];

    int ans = 0;
    for(int i=0; i<3; i++)
    {
        ans = max(ans, maxHap(n-1, i));
    }

    cout << ans << endl;

    return 0;
}
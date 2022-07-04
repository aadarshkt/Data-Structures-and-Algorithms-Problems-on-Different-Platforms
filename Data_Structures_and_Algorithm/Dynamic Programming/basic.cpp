#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 1;
int dp[MAX];

int fib(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if(n == 2)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = fib(n - 1) + fib(n - 2);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < MAX; i++)
    {
        dp[i] = -1;
    }

    cout << fib(5) << endl;

    return 0;
}
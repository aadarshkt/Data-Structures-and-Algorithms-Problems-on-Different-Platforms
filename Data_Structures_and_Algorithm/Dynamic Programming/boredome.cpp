#include <bits/stdc++.h>;
using namespace std;

const int MAX = 100000 + 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    long long arr[n];
    long long freq[100001] = {0};
    long long dp[100001] = {0};

    for(int i=0; i<n; i++) 
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }


    for(int i=0; i<n; i++)
    {
      
    }

    dp[1] = freq[1];

    for(int i=2; i<100001; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2] + i * freq[i]);
    }

    cout << dp[100000];
    return 0;
}
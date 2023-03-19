#include <bits/stdc++.h>
using namespace std;

int minCost(int i, int arr[], int k, int *lastCost[])
{
    for (int j = 0; j < count; ++j)
    {
        cout << "Hello" << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin>>n>>k;

    int h[n];

    int lastCost[n][k];


    for(int i=0; i<n; i++) cin>>h[i];


    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<k; j++)
        {
            if(i - j < 0)
            lastCost[i][j] = abs(h[i] - h[i-j-1]);
        }
    }

    return 0;
}
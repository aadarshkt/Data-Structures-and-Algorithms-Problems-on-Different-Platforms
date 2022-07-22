#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int arr[n + 1] = {0};

    while(k--)
    {
        int a, b;
        cin >> a >> b;

        arr[a - 1] += 1;
        arr[b] -= 1;
    }

    long long sum = 0;

    for(int i=0; i<n + 1; i++) 
    {
        sum += arr[i];
        arr[i] = sum;
    }

    sort(arr, arr + n);

    cout << arr[((n+1)/2) - 1] << endl;

    return 0;
}
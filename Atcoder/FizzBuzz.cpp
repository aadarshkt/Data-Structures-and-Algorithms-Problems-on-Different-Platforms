#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long int n, a, b;
    cin >> n >> a >> b;

    unsigned long long int sum = 0;

    for (long long i = 1; i <= n; i++)
    {
            sum += i;
    }

    unsigned long long int mulSum = 0;

    unsigned long long int i = 1, j = 1;
     
    while(a * i <= n && b * j <= n)
    {
        if(a * i == )
        mulSum += a * i;
        i++;
        j++;
    }

    while(true)
    {
        mulSum += b * j;
        j++;
    }

    if(b * (j-1) == a * (i - 1))
    {
        mulSum -= b * (j-1);
    }



    cout << sum - mulSum << endl;

    return 0;
}
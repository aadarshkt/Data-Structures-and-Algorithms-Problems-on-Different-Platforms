#include <bits/stdc++.h>
using namespace std;

long long sum(long long n)
{
    return n * (n + 1) / 2;
}

long long gcd(long long a, long long b)
{

    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, a, b;
    cin >> n >> a >> b;

    // Apporoach
    // s1 + s2 = calculate sum of all multiples of a and b upto n.
    // s2 = calculate sum of all multiples of LCM(a, b) upto n.
    // sum = total sum - s1 - s2 + s3;

    long long p = floor(n / a);
    long long q = floor(n / b);

    long long s1 = a * (sum(p));
    long long s2 = b * (sum(q));

    long long gcdNum = gcd(a, b);

    long long lcm = a * b / gcdNum;

    long long s3 = lcm * (sum(floor(n / lcm)));

    long long ans = sum(n) - s1 - s2 + s3;

    cout << ans << endl;

    return 0;
}
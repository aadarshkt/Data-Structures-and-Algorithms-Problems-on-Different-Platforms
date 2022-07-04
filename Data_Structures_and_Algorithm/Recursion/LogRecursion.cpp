#include <bits/stdc++.h>
using namespace std;

int16_t logBase2(int n)
{
    if (n == 1)
        return 0;

    return 1 + logBase2(n / 2);
}

int main()
{

    cout << logBase2(16);

    return 0;
}
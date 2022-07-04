#include <bits/stdc++.h>
using namespace std;

void binaryRecursion(int n)
{
    if(n==0)
        return;

    binaryRecursion(n/2);
    cout << n % 2;
}
 
int main()
{

    binaryRecursion(17);

    return 0;
}
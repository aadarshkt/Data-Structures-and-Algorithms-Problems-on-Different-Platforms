#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
    if(n==0)
        return;

    cout << n << " ";
    print(n-1);
}
 
int main()
{

    print(6);

    return 0;
}
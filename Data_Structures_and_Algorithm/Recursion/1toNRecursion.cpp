#include <bits/stdc++.h>
using namespace std;

//Approach -> Go to last of tail and start printing from that.
//Make recursion tree first.

void print(int n)
{
    if(n==0)
        return;

    print(n-1);
    cout << n  << " ";
}
 
int main()
{

    print(6);

    return 0;
}
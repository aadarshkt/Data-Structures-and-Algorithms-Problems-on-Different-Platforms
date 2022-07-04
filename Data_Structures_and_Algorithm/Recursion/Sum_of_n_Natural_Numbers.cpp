#include <bits/stdc++.h>
using namespace std;

//1. Make recursion tree that sums that number and number - 1;
//2. Thinking this way -> a function that can give sum of numbers upto n = that number + again that function with argument n - 1.

int sum(int n)
{
    if(n==0)
        return 0;

    return n + sum(n-1);
}
 
int main()
{

    cout << sum(5);

    return 0;
}
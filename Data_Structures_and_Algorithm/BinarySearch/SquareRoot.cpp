#include <bits/stdc++.h>
using namespace std;

//Writing your own code makes you a good coder...but after sometime solution is needed.

//This binary search uses the fact that if mid * mid is greater than the number itself (15) then we have to discard the upper mid range.

// I did it made certain changes in the algorithm to get more exact sqrt function.

double squareRoot(double l, double r, double x)
{
    double ans = -1;

    while (l <= r)
    {
        double m = (l+r) / 2;
        if(m * m == x)
        {
            return (m);
        }
        if (m * m > x)
        {
            r = m - 0.00000001;
        } else {
            l = m + 0.00000001;
            ans = m;//This part stores the value as a candidate output and also increases l by one from mid checking for higher values.
        }
    }
return ans;

}

int main()
{

    double x = 0.5;

    cout << "Square root of x is :" << squareRoot(0, 2 * x, x) << endl; // For fractionl inserts increase the interval for Binary Search.

    double a = 15;

    cout << "Square root of x is :" << squareRoot(0, a, a); 


    return 0;
}
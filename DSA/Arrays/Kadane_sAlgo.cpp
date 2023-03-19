#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < n; i++)
    {
         
        max_ending_here += a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }

    return max_so_far;
}

int minSubArraySum(int a[], int n){

    int min_so_far = INT_MAX, min_ending_here = 0;

    for (int i = 0; i < n; i++)
    {
        min_ending_here += a[i];
        if (min_so_far > min_ending_here)
            min_so_far = min_ending_here;

        if (min_ending_here > 0)
            min_ending_here = 0;
    }

    return min_so_far;

}



//The trick to understand this algo is -> When we are the first element the next element would either
// be equal or less or more, when equal or less we have already registered the max element in max_so_far
//when next is more we simply sum and get again max so far.

//One more method to find minimum sum is invert the elements then find max of elements.

int main()
{

    int a[] = {-18, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    cout << endl;
    cout << "Minimum contiguous sum is " << minSubArraySum(a, n);
    return 0;

    return 0;
}
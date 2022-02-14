#include <bits/stdc++.h>
using namespace std;

//Unsorted array with variable window length to check whether it has given sum.Contains only non-negative numbers.

int main()
{
    //Long solution.

    int arr[] = {1, 97, 20, 3, 10, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    // int curr_Sum = 0, given_Sum = 34;

    // bool visited = false;

    // for (int k = 1; k <= n; k++)
    // {

    //     for (int i = 0; i < k; i++)
    //     {
    //         curr_Sum += arr[i];
    //     }

    //     if (curr_Sum == given_Sum)
    //     {
    //         cout << "YEs" << endl;
    //         break;
    //     }

    //     for (int i = k; i < n; i++)
    //     {
    //         curr_Sum += arr[i] - arr[i - k];

    //         if (curr_Sum == given_Sum)
    //         {
    //             cout << "YEs" << endl;
    //             cout << k << endl;
    //             visited = true;
    //         }
    //     }

    //     curr_Sum = 0;
    // }

    // if(visited == false){
    //     cout << "NO" << endl;
    // }

    //Short solution.

    //we keep adding element to the window as long as the sum is smaller than the given sum.when sum becomes 
    //larger we start removing element from the beginning.

    int sum = 0, given_sum = 15, a = 0;

    for (int i = 0; i < n; i++)
    {

        if (sum < given_sum)
        {
            sum += arr[i];
        }

        if (sum > given_sum)
        {
            while (sum > given_sum)
            {
                sum -= arr[a];
                a++;
            }
        }

        if (sum == given_sum)
        {
            cout << "YEs" << endl;
            break;
        }
    }
    cout << sum << endl;

    return 0;
}
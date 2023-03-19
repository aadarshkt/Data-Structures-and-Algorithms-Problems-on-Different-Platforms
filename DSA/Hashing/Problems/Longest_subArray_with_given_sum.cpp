#include <bits/stdc++.h>
using namespace std;

int longest_sub_sum_naive(int arr[], int n, int sum)
{
    int longest = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];

            if (curr_sum == sum)
            {
                longest = max(longest, j - i + 1);
            }
        }
    }

    return longest;
}

int longest_sub_sum(int arr[], int n, int sum)
{
    unordered_map<int, int> m;

    int count = 1, prefix = 0, longest = -1;

    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];

        int b = prefix - sum;

        if(prefix == sum)
        {
            if(i+1 > longest)
            {
                longest = i+1;
            }
        }

        if (m.count(b))
        {
            auto it = m.find(b);
            int a = it->second;
            if ((i - a) > longest)
            {
                longest = i - a;
            }
        }
        else
        {
            m.insert({prefix, i});
        }
    }


    return longest;
}

int main()
{

    int arr[] = {5, 8, -4, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 9;

    cout << longest_sub_sum_naive(arr, n, sum) << endl;

    cout << longest_sub_sum(arr, n, sum);

    return 0;
}
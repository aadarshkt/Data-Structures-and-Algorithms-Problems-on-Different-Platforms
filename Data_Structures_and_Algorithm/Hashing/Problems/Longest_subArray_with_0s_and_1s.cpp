#include <bits/stdc++.h>
using namespace std;

//Make zero to -1 and then chech for longest subaray that has sum zero.

int longest_sub_given_sum(int arr[], int n, int sum)
{
    
    unordered_map<int, int> m;

    int count = 1, prefix = 0, longest = 0;

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

int long_sub_eq_0_1(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            arr[i] = -1;
        }
    }

    return longest_sub_given_sum(arr, n, 0);

}


 
int main()
{

    int arr[] = {1, 0, 1, 1, 1, 0, 0};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << long_sub_eq_0_1(arr, n);

    return 0;
}
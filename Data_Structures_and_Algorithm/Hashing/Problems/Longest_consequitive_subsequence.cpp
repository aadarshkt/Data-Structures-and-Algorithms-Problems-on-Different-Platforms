#include <bits/stdc++.h>
using namespace std;

//cannot find time complexity because loop is running even for those who are consecutive.

int con_sub_sequence(int arr[], int n)
{
    unordered_set<int> m(arr, arr + n);

    int longest = 1;

    int longest_sub = 0;

    for(auto x : m)
    {
        longest = 1;

        int a = x - 1;

        int b = x;

        if (m.count(a) == 1)
        {
            continue;
        }
        else
        {
            while (m.find(b + longest) != m.end())
            {
                longest++;
            }
        }

        longest_sub = max(longest_sub, longest);
    }

    return longest_sub;
}

int main()
{

    int arr[] = {1, 3, 4, 3, 3, 2, 9, 10};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << con_sub_sequence(arr, n);

    return 0;
}
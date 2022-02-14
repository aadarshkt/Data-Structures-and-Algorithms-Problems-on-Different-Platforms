#include <bits/stdc++.h>
using namespace std;

//common subarray having same sum. 

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


int longest_common_span(int a[], int b[], int n)
{
    int temp[n];

    for(int i=0; i<n; i++)
    {
       temp[i] = a[i] - b[i]; 
    }

    return longest_sub_sum(temp, n, 0);
}
 
int main()
{

    int a[] = {0, 1, 0, 0, 0, 0};
    int b[] = {1, 0, 0, 1, 0, 0};

    int c = sizeof(a) / sizeof(a[0]);

    cout << longest_common_span(a, b, c);

    return 0;
}
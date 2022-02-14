#include <bits/stdc++.h>
using namespace std;

//Gazab kar diya mene//cycle today - 8 10 am 27-07-2021//My solution.//Community owned assets.

//space - O(n) and Time - O(n)

void findPair(int arr[], int n, int sum)
{
    unordered_map<int, int> m;

    int count, a;

    for (int i = 0; i < n; i++)
    {
        count = 1;

        if (m.count(arr[i]))
        {
            auto it = m.find(arr[i]);
            it->second++;
        }
        else
        {
            m.insert({arr[i], count});
        }
    }

    for(int i=0; i<n; i++)
    {
        auto it = m.find(arr[i]);
        it->second--;
        a = sum - arr[i];

        auto it2 = m.find(a);

        if(it2 != m.end())
        {
            if(it2->second > 0)
            {
                cout << arr[i] << " and " << it2->first;
                break;
            }
        } 

        it->second++;
    }

}

int main()
{

    int arr[] = {3, 3, 8, 15, -8};

    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 6;

    findPair(arr, n, sum);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void occur(int arr[], int n, int k)
{
    int a = ceil(n / k);

    unordered_map<int, int> m;

    // To create a frequency map
    for(int i=0; i<n; i++)
    {
        m[arr[i]]++;
    }

    // for(int i=0; i<n; i++)
    // {
    //     if(m.count(arr[i]))
    //     {
    //         auto it = m.find(arr[i]);
    //         it->second++;
    //     } else 
    //     {
    //         m.insert({arr[i], 1});
    //     }

    
    // }

    for(auto x : m)
    {
        if(x.second > a)
        {
            cout << x.first << " ";
        }
    }

    cout << endl;

    cout << m.size() << endl;
}
 
int main()
{

    int arr[] = {30, 10, 20, 20, 10, 20, 30, 30};

    int k = 4;

    int n = sizeof(arr) / sizeof(arr[0]);

    occur(arr, n, k);

    return 0;
}
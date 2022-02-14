#include <bits/stdc++.h>
using namespace std;

//time 0(n) exact if we consider hash operations to be 0(1)
//space O(n) ...

void frequency(int arr[], int n)
{
    unordered_map<int, int> m;

    int count = 1;

    for(int i=0; i<n; i++)
    {
        if(m.count(arr[i]))
        {
          auto it = m.find(arr[i]);
          it->second = it->second + 1;
        } else 
        {
          m.insert({arr[i], count});
        }
        
    }


    for(auto x : m)
    {
        cout << x.first << ' ' << x.second << endl;
    }
}

//Much shorter code.

void frequencyshorter(int arr[], int n)
{
    unordered_map<int, int> m;

    for(int i=0; i<n; i++)
       m[arr[i]]++;

    
    cout << endl;

    for(auto x : m) cout << x.first << " " << x.second << endl;
    
}
 
int main()
{

    int arr[] = {10, 20, 10, 12, 12, 15, 7, 10, 20, 7, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    frequency(arr, n);

    frequencyshorter(arr, n);

    return 0;
}
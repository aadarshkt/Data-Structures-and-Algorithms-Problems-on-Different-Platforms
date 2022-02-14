#include <bits/stdc++.h>
using namespace std;

//1st solution

void intersection(int arr[], int arr2[], int n, int n2)
{

     unordered_map<int, int> m;

    for(int i=0; i<n; i++)
       m[arr[i]]++;

    for(int i=0; i<n2; i++)
        m[arr2[i]]++;

    int n1 = m.size();

    for(auto it=m.begin(); it != m.end(); it++)
    {

        if(it->second > 1)
        {
            cout << it->first << endl;
        }
    }
}

//2nd solution 

void intersection1(int arr[], int arr2[], int n, int n2)
{
    unordered_set<int> s(arr, arr+n);

     
    for(int i=0; i<n2; i++)
    {
        if(s.count(arr2[i]))
        {
            cout << arr2[i] << endl;
            s.erase(arr2[i]);
        }
    }
}

 
int main()
{

    int arr[] = {5, 10, 20, 30};
    int arr2[] = {30, 40, 50, 5};

    int n = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    intersection(arr, arr2, n, n2);
    cout << endl;
    intersection1(arr, arr2, n, n2);
    return 0;
}
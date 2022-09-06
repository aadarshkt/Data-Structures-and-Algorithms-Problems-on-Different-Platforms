#include <bits/stdc++.h>
using namespace std;

//The idea is to use prefix and hash table both.

//Killer

bool sub_zero(int arr[], int n)
{
    int prefix[n], sum = 0;

    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        prefix[i] = sum;
        if(sum == 0)
        {
            return true;
        }   
    }



    // Pair with a given sum

    unordered_map<int, int> m;

    int count;

    for (int i = 0; i < n; i++)
    {
        count = 1;

        if (m.count(prefix[i]))
        {
            auto it = m.find(prefix[i]);
            it->second++;
        }
        else
        {
            m.insert({prefix[i], count});
        }
    }

    //simply find a prefix sum element having duplicate.

    for(int i=0; i<n; i++)
    {
        auto it = m.find(prefix[i]);


        if(it != m.end())
        {
            if(it->second > 1)
            {
                return true;
                break;
            }
        } 
    }

    return false;
}

//Above I have made frequency distribution table. Alternate solution is initialize empty hash keep putting elements in it. when we are to put
// a element that is already in the hash return true;

//Below is much better solution 

//Time - O(n) and space - O(1)

bool sub_zero_alternate(int arr[], int n)
{
    unordered_set<int> s;

    int prefix_sum = 0;

    for(int i=0; i<n; i++)
    {


        prefix_sum += arr[i];


        if(prefix_sum == 0)
        {
            return true;
        }

        if(s.count(prefix_sum))
        {
            return true;
        } else 
        {
            s.insert(prefix_sum);
        }

        

    }

     return false;

}

int main()
{

    int arr[] = {0, 4, 13, 3, -10, 5, 6, 32};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << sub_zero(arr, n) << endl;
    cout << sub_zero_alternate(arr, n);

    return 0;
}
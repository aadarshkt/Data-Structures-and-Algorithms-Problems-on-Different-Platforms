#include <bits/stdc++.h>
using namespace std;

//struct 

struct MyHash{

    int Bucket;
    list<int> *table;//list of pointers.meant for storing int.

    // int Myhash(int b)
    // {
    //     Bucket = b;
    //     table = new list<int>[b];
    // }

    void insert(int key)
    {
        int i = key % Bucket;
        table[i].push_back(key);
    }

    bool search(int key)
    {
        int i = key % Bucket;
        for(auto x : table[i])///this x goes to every x of table[i]//making of O(1+alpha)
        {
            if(x == key)
            {
                return true;
            } else 
            {
                return false;
            }
        }
    }

    void remove(int key)
    {
        int i = key % Bucket;
        table[i].remove(key);

    }
};
 
int main()
{

    

    return 0;
}
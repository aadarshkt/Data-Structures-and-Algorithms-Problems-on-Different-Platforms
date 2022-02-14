#include <bits/stdc++.h>
using namespace std;

//Hashing includes undordered map and unordered set 
//We have to insert certain items and search certain items. so hashing is best.

//time - O(m+n) space O(m+n)

void unionArray(int a[], int b[], int c, int d)
{
    unordered_set<int> s1(a, a+c), s2(b, b+d);

    //better is to insert all elements in same set.

    int n = s1.size();

    for(auto it=s1.begin(); it != s1.end(); it++)
    {
        int e = *(it);
        s2.erase(e);
    }

    cout << s1.size() + s2.size();


}

int main()
{

    int a[] = {15, 20, 5, 15};
    int b[] = {15, 15, 15, 10, 20};

    int c =  sizeof(a) / sizeof(a[0]);
    int d = sizeof(b) / sizeof(b[0]);

    unionArray(a, b, c, d);
    return 0;
}
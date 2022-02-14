#include <bits/stdc++.h>
using namespace std;
 
int main()
{

    unordered_set<int> s;

    s.insert(5);
    s.insert(25);
    s.insert(15);
    s.insert(35);
    s.insert(55);

    for(int x : s)
    {
        cout << x << " ";
    }

    cout << endl;

    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl;

    cout << s.size() << endl;
    // s.clear();
    // cout << s.size() << endl;

    //find a element.

    if(s.find(25) == s.end())
    {
        cout << "Not found" << endl;
    } else 
    {
        cout << "Found " << *(s.find(25)) << endl;
    }

    if(s.count(25))
    {
        cout << "Mil Gaya" << endl;
    }

    //Erase a element.

    s.erase(25);

    auto it = s.find(55);

    s.erase(it);

    cout << s.size() << endl;

    s.erase(s.begin(), s.end());

    cout << s.size();



    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int main()
{

    unordered_map<string, int> m;

    m["sakura"] = 30;//one way

    m.insert({{"Aadarsh", 11}, {"India", 15}, {"Technology", 20}, {"Full potential", 25}, 
    {"Education Hub", 30}, {"Collective enlightenment", 35}});



    for(auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }

    if(m.find("Technology") != m.end())
    {
        cout << "Mil Gaya" << endl;
    } else 
    {
        cout << "Not found" << endl;
    }

    cout << m.count("Technology") << endl;
    cout << m.count("Hello") << endl;

    //Better to use m.count("Technology")

    auto it = m.find("Technology");

    if(it != m.end())
    {
        cout << it->first << " " << it->second << endl;
    }

    //another way to print

    // for(auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    //remove

    m.erase("Aadarsh");//orm.erase(any iterator)

    cout << m.size() << endl;

    return 0;
}
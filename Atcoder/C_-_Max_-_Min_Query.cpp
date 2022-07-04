#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    cin >> q;

    multiset<int> s;

    while (q--)
    {
        int first;
        cin >> first;

        if (first == 1)
        {
            int b;
            cin >> b;

            s.insert(b);
        }
        else if (first == 3)
        {
              cout << *s.rbegin() - *s.begin() << endl; //NSMA
        }
        else if (first == 2)
        {
            int x, c;
            cin >> x >> c;

            int n = s.size();

            while(c-- && s.find(x) != s.end())
            {
                s.erase(s.find(x)); //deletes only one instance.
            }
        }
    }

    return 0;
}
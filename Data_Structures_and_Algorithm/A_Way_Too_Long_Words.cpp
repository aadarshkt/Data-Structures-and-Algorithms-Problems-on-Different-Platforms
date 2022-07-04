#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a;
    cin >> a;
    while (a--)
    {
        string b;
        cin >> b;

        int l = b.length();

        if (l > 10)
        {
            cout << b.substr(0, 1) + to_string(l - 2) + b.substr(l - 1, l) << endl;
        }
        else
        {
            cout << b << endl;
        }
    }

    return 0;
}
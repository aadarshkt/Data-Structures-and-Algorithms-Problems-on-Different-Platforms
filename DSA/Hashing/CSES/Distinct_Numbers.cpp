#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);

    set<int> s;

    for(int &x : arr) 
    {
        cin >> x;
        s.insert(x);
    }

    int size = s.size();

    cout << size << endl;

    return 0;
}
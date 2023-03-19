#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        if(n % 2 != 0) cout << -1 << endl;
        else 
        {
            cout << 0 << " " << n / 2 << " " << n / 2 << endl;
        }
    }



    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    map<int, int> m;

    int a = -1, b = -1;

    for(int i=0; i<n; i++) 
    {
        int c;
        cin >> c;
        
        if(m.count(x - c))
        {
            b = i;
            a = m[x - c];
        }
        
        if(!m.count(c))
        {
            m[c] = i;
        }
    }

    if(a == -1 || b == -1) cout << "IMPOSSIBLE" << endl;
    else cout << a + 1 << " " << b + 1 << endl;

    return 0;
}
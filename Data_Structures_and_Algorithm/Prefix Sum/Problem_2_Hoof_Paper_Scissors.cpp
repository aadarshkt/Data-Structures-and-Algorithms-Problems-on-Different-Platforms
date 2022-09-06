#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
	// freopen("div7.in", "r", stdin);
    // // the following line creates/overwrites the output file
    // freopen("div7.out", "w", stdout);


    int n;
    cin >> n;

    char arr[n];

    int prefix[n], suffix[n];

    map<char, int> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]]++;
        prefix[i] = max({m['H'], m['P'], m['S']});

    }

    m.clear();

    for (int i = n - 1; i >= 0; i--)
    {
        m[arr[i]]++;
        suffix[i] = max({m['H'], m['P'], m['S']});
    }

    int ans = 0;

    for(int i=0; i<n-1; i++)
    {
        ans = max(ans, prefix[i] + suffix[i + 1]);
    }  

    ans = max({ans, prefix[n-1]});

    cout << ans << endl;

    return 0;
}
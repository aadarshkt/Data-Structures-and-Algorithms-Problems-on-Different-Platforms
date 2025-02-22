#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<vector<vector<int>>> st;
    
    vector<vector<int>> initial = {
		{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 0, 15}
	};

    st.insert(initial);

    vector<vector<int>> w = {
		{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 0, 15}
	};

    if(st.count(w))cout<<"YES"<<'\n';
    if(st.count(initial))cout<<"Yes"<<'\n';

    return 0;
}